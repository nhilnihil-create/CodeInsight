#include <bits/stdc++.h>
using namespace std;

//全探索では遅い
//上手く探索する方法を考える
//xが決まればyも自動的に決まる
int main()
{
    int c[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> c[i][j];
        }
    }

    int x[3], y[3];
    x[0] = 0;
    for (int i = 0; i < 3; i++)
    {
        y[i] = c[0][i] - x[0];
    }

    for (int i = 0; i < 3; i++)
    {
        x[i] = c[i][0] - y[0];
    }

    bool good = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (x[i] + y[j] != c[i][j])
                good = false;
        }
    }

    cout << (good ? "Yes" : "No") << endl;
}
