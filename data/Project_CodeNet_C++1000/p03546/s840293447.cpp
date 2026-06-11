#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll h, w;
    cin >> h >> w;
    vector<vector<ll> > c(10, vector<ll>(10)), d(10, vector<ll>(10, INF));
    vector<vector<ll> > a(h, vector<ll>(w));
    rep1(i, 10) rep1(j, 10) cin >> c[i][j];
    ll change;
    rep1(k, 10) rep1(i, 10) rep1(j, 10){
        c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
    }
    ll ans = 0;
    rep1(i, h) rep1(j, w){
        ll a;
        cin >> a;
        if (a==-1) continue;
        ans += c[a][1];
    }
    cout << ans << endl;
    //printf("%.12f", ans);
}