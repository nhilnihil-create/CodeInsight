#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll max_N = 21 + 1, INF = 1e15, MOD = 1e9 + 7, max_mask = (1LL << 21) + 5;
bool compat[max_N][max_N];
ll DP[max_N][max_mask], N, done;

ll match_ways(ll pos, ll mask)
{
    if (pos == N)
        return (mask == done);
    ll &res = DP[pos][mask];
    if (res != -1)
        return res;
    res = 0;
    for (int i = 0; i < N; ++i)
    {
        if (mask & (1LL << i))
            continue;
        if (!compat[pos][i])
            continue;
        res += match_ways(pos + 1, mask | (1LL << i));
        if (res >= MOD)
            res -= MOD;
    }
    return res;
}

int main()
{
    cin >> N;
    done = (1LL << N) - 1;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> compat[i][j];
    memset(DP, -1, sizeof(DP));
    cout << match_ways(0, 0) << "\n";
    return 0;
}