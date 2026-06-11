#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int c[3][3];
    bool ans = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> c[i][j];
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (c[i][j] + c[i + 1][j + 1] != c[i + 1][j] + c[i][j + 1])
            {
                ans = 0;
                break;
            }
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
}