#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define INF LLONG_MAX
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll n, k; cin >> n >> k;
    ll z = 0, h = 0;
    for (size_t i = 1; i <= n; i++) if (i % k == 0) ++z;
    if (k % 2 == 0) for (int i = 1; i <= n; i++) if (i % k == k / 2) ++h;
    ll ans = 0;
    ans += (ll)pow(z, 3) + (ll)pow(h, 3);
    cout << ans << endl;
    
    return 0;
}