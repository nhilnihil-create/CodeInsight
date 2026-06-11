#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

int A, B;

int main()
{
    cin >> A >> B;
    A--, B--;

    vector<vector<char>> grid(100, vector<char>(100));
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (i < 50)
                grid[i][j] = '#';
            else
                grid[i][j] = '.';
        }
    }

    for (int i = 0; i < 49 && A > 0; i += 2)
    {
        for (int j = 0; j < 100 && A > 0; j += 2)
        {
            grid[i][j] = '.';
            A--;
        }
    }

    for (int i = 51; i < 100 && B > 0; i += 2)
    {
        for (int j = 0; j < 100 && B > 0; j += 2)
        {
            grid[i][j] = '#';
            B--;
        }
    }

    puts("100 100");

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}
