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
    ll H, W;
    cin >> H >> W;

    ll D;
    cin >> D;

    vector<ll> A(H * W);
    rep(i, H * W) cin >> A[i];
    
    ll Q;
    cin >> Q;
    vector<ll> L(Q), R(Q);
    rep(i, Q) cin >> L[i] >> R[i];
    

    vector<ll> a2p(H * W + 1);
    rep(i, A.size()) {
        a2p[A[i]] = i;
    }

    // 一番小さい値から iに行くまでのコストc[i];
    vector<ll> c(H * W + 1);
    repi(v, c.size()) {
        if (c[v] > 0) {
            continue;
        }

        for (ll j = 1; v + j * D < c.size(); j++) {
            ll v1 = v + (j-1) * D;
            ll v2 = v + j * D;
            ll ind1 = a2p[v1];
            ll ind2 = a2p[v2];
            ll x1 = ind1 % W;
            ll y1 = ind1 / W;
            ll x2 = ind2 % W;
            ll y2 = ind2 / W;
            c[v2] = c[v1] + abs(x1-x2)+abs(y1-y2);
        }
    }

    rep(i, Q) {
        ll res = c[R[i]] - c[L[i]];
        put(res);
    }
}
signed main(){ Main();return 0;}