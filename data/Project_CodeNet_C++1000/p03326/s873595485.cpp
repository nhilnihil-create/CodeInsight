#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> x(n), y(n), z(n);
    rep(i, n) cin >> x[i] >> y[i] >> z[i];

    ll res = 0;
    rep(pat, 1 << 3) {
        vector<ll> a = x;
        vector<ll> b = y;
        vector<ll> c = z;

        if (pat & (1 << 0)) {
            rep(i, n) a[i] = -a[i];
        }

        if (pat & (1 << 1)) {
            rep(i, n) b[i] = -b[i];
        }

        if (pat & (1 << 2)) {
            rep(i, n) c[i] = -c[i];
        }

        vector<ll> d(n);
        rep(i, n) d[i] = a[i] + b[i] + c[i];

        sort(all(d));
        reverse(all(d));

        ll v = 0;
        rep(i, m) {
            v += d[i];
        }

        res = max(res, v);
    }

    put(res);
    
}
signed main(){ Main();return 0;}