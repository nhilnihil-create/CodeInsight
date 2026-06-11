#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll max_n = 17, inf = 1e15, mod = 1e9 + 7, max_mask = (1LL << 17) + 10;
ll n, a[max_n][max_n];
ll DP[max_mask], gscore[max_mask];

void calc_scores(ll mask)
{
    ll score = 0;
    for (ll i = 0; i < 17; ++i)
    {
        for (ll j = i + 1; j < 17; ++j)
            if( ((mask >> i) & 1) & ((mask >> j) & 1))
                score += a[i][j];
    }
    gscore[mask] = score;
}

ll max_score(ll mask)
{
    if (mask == 0)
        return 0;
    ll &ans = DP[mask];
    if (ans != -inf)
        return ans;
    ans = 0;
    for (ll submask = mask; submask > 0; submask = (submask - 1) & mask)
        ans = max(ans, gscore[submask] + max_score((submask ^ mask) & mask));
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    ll res = -inf;
    ll done = (1LL << n) - 1;
    for (ll i = 1; i <= done; ++i)
        calc_scores(i);
    fill(DP, DP + max_mask, -inf);
    res = max_score(done);
    cout << res << "\n";
    return 0;
}