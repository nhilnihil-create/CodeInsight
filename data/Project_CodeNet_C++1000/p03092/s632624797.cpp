#include <bits/stdc++.h>

using namespace std;

const int Nmax = 5005;
typedef long long ll;

int n, A, B, i, j, p;
int smaller[Nmax], a[Nmax];

int main()
{
//    freopen("input", "r", stdin);
    cin.sync_with_stdio(false);

    cin >> n >> B >> A;
    for(i=1; i<=n; ++i) cin >> a[i];

    vector<ll> dp(n+2), new_dp(n+2);

    for(i=1; i<=n; ++i)
    {
        for(p=1; p<=n; ++p)
            if(a[p] == i) break;

        for(j=p; j<=n; ++j)
            smaller[j]++;

        for(j=1; j<p; ++j) new_dp[j] = dp[j];

        for(j=p; j<=n; ++j)
            new_dp[j] = min(dp[p-1] + (ll) A * (smaller[j] - smaller[p]), dp[j] + B);

        swap(dp, new_dp);
    }

    cout << dp[n] << '\n';
    return 0;
}
