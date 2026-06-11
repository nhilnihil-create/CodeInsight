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
    ll n, C;
    cin >> n >> C;

    vector<ll> D(C * C);
    rep(i, C * C) cin >> D[i];
    vector<ll> c(n * n);
    rep(i, n * n) cin >> c[i];
    
    vector<vector<ll>> cnt(3, vector<ll>(31));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ll ind = (i-1) * n + (j-1);
            cnt[(i+j)%3][c[ind]]++;
        }
    }

    ll res = 1e18;
    for (int p = 1; p <= C; p++) {
        for (int q = 1; q <= C; q++) {
            for (int r = 1; r <= C; r++) {
                if (p == q || q == r || r == p) {
                    continue;
                }

                // %3=0をp, 1をq, 2をr
                ll v = 0;
                vector<ll> colors = {p, q, r};
                rep(k, 3) {
                    repi(i, cnt[k].size()) {
                        ll from = i;
                        ll count = cnt[k][i];
                        ll to = colors[k];
                        ll ind = (from-1) * C + (to-1);
                        if (count >= 1) {
                            v += D[ind] * count;
                        }
                    }
                }
                res = min(res, v);
            }
        }
    }

    put(res);
}
signed main(){ Main();return 0;}