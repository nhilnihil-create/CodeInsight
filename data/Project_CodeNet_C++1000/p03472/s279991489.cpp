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
    ll n, H;
    cin >> n >> H;

    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    ll maxA = *max_element(all(a));

    typedef pair<ll, ll> P;
    vector<P> p(b.size());
    rep(i, b.size()) p[i] = P(b[i], a[i]);
    sort(all(p));
    reverse(all(p));
    
    ll res = 0;
    rep(i, n) {
        ll B = p[i].first;
        if (maxA < B) {
            H -= B;
            res++;
            if (H <= 0) {
                put(res);
                return;
            }
        }
        else {
            break;
        }
    }

    res += (H + maxA - 1) / maxA;
    put(res);
}
signed main(){ Main();return 0;}