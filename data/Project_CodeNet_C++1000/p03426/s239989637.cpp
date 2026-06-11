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
const int MAX = 100005;

struct data {int x, y, value;};

int main() {
    int h, w, d; cin >> h >> w >> d;
    int M = 300*300;
    int m = M+d-1;
    vector<vector<P>> data(d,vector<P>(m/d));
    REP(i,h+1)REP(j,w+1) {
        int x; cin >> x;
        if (x%d != 0) data[x%d][x/d] = P(i,j);
        else data[x%d][x/d-1] = P(i,j);
    }
    vvint dis(d,vint(m/d+1,0));
    rep(i,d) {
        REP(j,m/d+1) {
            int x = abs(data[i][j].second-data[i][j-1].second);
            int y = abs(data[i][j].first-data[i][j-1].first);
            dis[i][j] = dis[i][j-1] + x + y;
        }
    }
    int q; cin >> q;
    rep(i,q) {
        int l, r; cin >> l >> r;
        if (r%d != 0) cout << dis[r%d][r/d]-dis[l%d][l/d] << endl;
        else cout << dis[r%d][r/d-1]-dis[l%d][l/d-1] << endl;
    }
}