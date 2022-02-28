#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;
int dong[8], cot[8], cheodausac[15], cheodauhuyen[15];
int dem = 0;
char banco[8][8];
void khoitaobanco()
{
    banco[0][0] = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            banco[i][j]++;
}
void khoitao()
{
    int i;
    for (i = 0; i < 8; i++)
    {
        cot[i] = 1;
        dong[i] = -1;
    }
    for (i = 0; i < 15; i++)
    {
        cheodausac[i] = 1;
        cheodauhuyen[i] = 1;
    }
}
void thu(int i)
{
    int j;
    khoitaobanco();
    for (j = 0; j < 8; j++)
        {
        if (cot[j] == 1 && cheodausac[i + j] == 1 && cheodauhuyen[i - j + 7] == 1)
        {
            dong[i] = j;
            cot[j] = 0;
            cheodausac[i + j] = 0;
            cheodauhuyen[i - j + 7] = 0;
            if (i < 7)
                thu(i + 1);
            else
            {
                dem++;
                for (int i = 0; i < 8; i++)
                {
                    banco[i][dong[i]] = 'Q';
                }
            }
            if (dem == 1) break;
            cot[j] = 1;
            cheodausac[i + j] = 1;
            cheodauhuyen[i - j + 7] = 1;
        }
    }
}
void timquanhau()
{
    int i;
    khoitao();
    thu(0);
}
void hienthisaumoinuocdi()
{
    cout << "\t\tBAN CO\n\n";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << banco[i][j] << "   ";
        }
        cout << "\n\n";
    }
}
int main()
{
    timquanhau();
    hienthisaumoinuocdi();
    //getch();
    return 0;
}
