#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll N, M; cin >> N >> M;
    ll maxn = 1;
    for (ll i = 1; i <= sqrt(M); i++) {
        if (M % i) continue;
        ll x = i, y = M / i;
        if (N <= x && x <= M) maxn = max(maxn, y);
        if (N <= y && y <= M) maxn = max(maxn, x);
    }
    cout << maxn << endl;
    return 0;
}