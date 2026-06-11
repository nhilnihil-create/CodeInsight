#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define inf LLONG_MAX
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll n, m; cin >> n >> m;
    if (n == 1 || m == 1) {
        if (n == 1 && m == 1) cout << 1 << endl;
        else cout << max(0ll, n * m - 2) << endl;
    } else {
        cout << max(0ll, (n - 2) * (m - 2)) << endl;
    }
    return 0;
}