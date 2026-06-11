#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int nax = 20;

ll mat[nax][nax];

vector<ll>dp;
vector<ll>prec;

void solve(vector<int> free, int mask, int group, ll current_score, int poz)
{
    if(poz == free.size())
    {
        dp[mask] = max(dp[mask], current_score + prec[group]);
        return;
    }

    dp[mask] = max(dp[mask], current_score + prec[group]);
    solve(free, mask, group, current_score, poz + 1);
    solve(free, mask + (1 << free[poz]), group + (1 << free[poz]), current_score, poz + 1);
}

int main()
{
    int n;

    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];

    dp.resize(1 << n);
    prec.resize(1 << n);

    for(int mask = 0; mask < (1 << n); mask++)
        for(int a = 0; a < n; a++)
            if(mask & (1 << a))
                for(int b = a + 1; b < n; b++)
                    if(mask & (1 << b))
                        prec[mask] += mat[a][b];

    for(int mask = 0; mask < (1 << n); mask++)
    {
        vector<int>free;
        for(int a = 0; a < n; a++)
            if(!(mask & (1 << a)))
                free.push_back(a);

        solve(free, mask, 0, dp[mask], 0);
    }

    cout << dp[(1 << n) - 1];

    return 0;
}
