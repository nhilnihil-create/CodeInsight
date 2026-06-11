#include <algorithm>
#include <iostream>
#include <string>

#include <vector>
#include <cmath>
#include <limits>
#include <functional>
using namespace std;

int main()
{
    int N, K;
    int c[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> c[i][j];
        }
    }

    int a1 = 1;
    int b[3];
    int a2[3];
    int a3[3];
    bool flag1 = false,flag2=false;

    for (int i = 0; i < 3; i++)
    {
        b[i] = c[0][i] - a1;
    }

    for (int i = 0; i < 3; i++)
    {
        a2[i] = c[1][i] - b[i];
    }

    if (a2[0] == a2[1] && a2[1] == a2[2])
    {
        flag1 = true;
    }
    else
    {
        flag1 = false;
    }

    for (int i = 0; i < 3; i++)
    {
        a3[i] = c[2][i] - b[i];
    }

    if (a3[0] == a3[1] && a3[1] == a3[2])
    {
        flag2 = true;
    }
    else
    {
        flag2 = false;
    }

    if (flag1&&flag2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

   

    return 0;
}