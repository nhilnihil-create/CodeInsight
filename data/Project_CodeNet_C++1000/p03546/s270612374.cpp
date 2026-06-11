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
    vector<ll> c(100);
    rep(i, 100) cin >> c[i];
    vector<ll> A(H * W);
    rep(i, H * W) cin >> A[i];
    
    
    // Warshall–Floyd 
    ll INF = 1e18;
    vector<vector<ll> > d(10, vector<ll>(10, INF));
    rep(i, c.size()) {
        int a = i / 10;
        int b = i % 10;
        d[a][b] = c[i];
    }
    ll n = 10;
    rep(k, n) {
        rep (i, n) {
            rep (j, n) {
                if (d[i][k] < INF && d[k][j] < INF) {
                    d[i][j] = min(
                        d[i][j], d[i][k] + d[k][j]);
                }
            }
        }        
    }

    ll res = 0;
    rep(i, A.size()) {
        if (A[i] >= 0) {
            res += d[A[i]][1];
        }
    }
    
    put(res);
}
signed main(){ Main();return 0;}