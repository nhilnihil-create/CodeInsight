#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

int f[100][10];
int p[100][11];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 10; ++j)
            cin >> f[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= 10; ++j)
            cin >> p[i][j];

    int sol = -1e9;
    for (int i = 1; i < (1 << 10); ++i)
    {
        vector<int> c(n);
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < 10; ++k)
                if (f[j][k] && (i & (1 << k)))
                    c[j]++;

        int profit = 0;
        for (int j = 0; j < n; ++j)
            profit += p[j][c[j]];
        sol = max(sol, profit);
    }
    cout << sol;
}
