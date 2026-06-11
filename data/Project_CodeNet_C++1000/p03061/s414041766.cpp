#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

signed main()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    vector<ll> l(n+1), r(n+1);
    rep(i, n) l[i+1] = gcd(l[i], a[i]);
    for (int i = n - 1; i >= 0; i--) r[i] = gcd(r[i+1], a[i]);

    ll ma = 0;
    rep(i, n) {
        ll v = gcd(l[i], r[i + 1]);
        ma = max(v, ma);
    }

    put(ma);
    return 0;
}