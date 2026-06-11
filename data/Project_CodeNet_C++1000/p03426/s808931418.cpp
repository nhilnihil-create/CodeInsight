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

int main() {
    int h, w, d; cin >> h >> w >> d;
    vint px(90001), py(90001);
    REP(i,h+1)REP(j,w+1) {
        int x; cin >> x;
        px[x] = j;
        py[x] = i;
    }
    vint dis(90001,0);
    for (int i = d+1; i < 90001; i++) {
        dis[i] = dis[i-d]+abs(px[i]-px[i-d])+abs(py[i]-py[i-d]);
    }
    int q; cin >> q;
    rep(i,q) {
        int l, r; cin >> l >> r;
        cout << dis[r]-dis[l] << endl;
    }
}