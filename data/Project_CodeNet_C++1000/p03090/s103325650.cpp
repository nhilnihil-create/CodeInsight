#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
bool adj[MAXN + 1][MAXN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            adj[i][j] = adj[j][i] = true;
        }
    }
    int first, second;
    first = 1;
    if (n % 2 == 0)
        second = n;
    else
        second = n - 1;
    int m = n * (n - 1) / 2;
    while (first < second)
    {
        adj[first][second] = adj[second][first] = false;
        m--;
        first++;
        second--;
    }
    cout << m << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (adj[i][j])
                cout << i << " " << j << endl;
        }
    }
    return 0;
}
