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
    ll n, m, Q;
    cin >> n >> m >> Q;

    vector<ll> L(m), R(m);
    rep(i, m) cin >> L[i] >> R[i];
    vector<ll> p(Q), q(Q);
    rep(i, Q) cin >> p[i] >> q[i];
    
    vector<vector<ll>> LR(501, vector<ll>(501));
    rep(i, m) {
        LR[L[i]][R[i]]++;
    }
    
    vector<vector<ll>> S(501, vector<ll>(501));
    rep(i, 501) {
        for(int j = 1; j <= 500; j++) {
            S[i][j] = S[i][j - 1] + LR[i][j];
        }
    }

    rep(ind, Q) {
        ll pi = p[ind];
        ll qi = q[ind];
        // (pi,pi), (pi,pi+1), ... (pi,qi), (pi+1,pi), ... (qi,qi)の総和
        ll res = 0;
        for (int i = pi; i <= qi; i++) {
            res += S[i][qi] - S[i][pi-1];
        }
        put(res);
    }
    
}
signed main(){ Main();return 0;}