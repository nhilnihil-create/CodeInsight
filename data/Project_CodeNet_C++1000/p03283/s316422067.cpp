#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

int main() {
    int n, m, q; cin >> n >> m >> q;
    vvint accum(n+1,vint(n+1,0));
    rep(i,m) {
        int l, r; cin >> l >> r;
        accum[l][r]++;
    }
    REP(i,n+1)REP(j,n+1) {
        accum[i][j] += accum[i-1][j] + accum[i][j-1] - accum[i-1][j-1];
    }
    rep(i,q) {
        int p, q; cin >> p >> q;
        int ans = accum[n][q] - accum[p-1][q];
        printf("%d\n",ans);
    }
}