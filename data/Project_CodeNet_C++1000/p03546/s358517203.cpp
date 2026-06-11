#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void WarshallFloyd(int n, V<V<int>> &g) {
    rep(k,n)rep(i,n)rep(j,n) {
        chmin(g[i][j], g[i][k] + g[k][j]);
    }
}


int main(){
    
    int h, w;
    cin >> h >> w;
    V<V<int>> g(10, V<int>(10));
    rep(i,10)rep(j,10) {
        int c;
        cin >> c;
        if(c == 0) c = inf;
        g[i][j] = c;
    }
    V<V<int>> a(h, V<int>(w));
    WarshallFloyd(10, g);

    int ans = 0;
    rep(i,h)rep(j,w) {
        int c;
        cin >> c;
        if(c == -1 || c == 1) continue;
        ans += g[c][1];
    }
    cout << ans << endl;
}