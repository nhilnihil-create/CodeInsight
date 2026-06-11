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

    vector<ll> a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i];
    
    typedef pair<ll, ll> P;
    vector<P> p(a.size());
    rep(i, a.size()) p[i] = P(b[i], a[i]);

    sort(all(p));

    ll latest = -1;
    ll res = 0;
    rep(i, m) {
        ll A = p[i].second;
        ll B = p[i].first;
        if (A <= latest) {

        }
        else {
            latest = B - 1;
            res++;
        }
    }

    put(res);
}
signed main(){ Main();return 0;}