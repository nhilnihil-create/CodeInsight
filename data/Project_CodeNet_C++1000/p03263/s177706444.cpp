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

struct op {int x, y, x2, y2;};

int main(){
    
    int h, w;
    cin >> h >> w;
    V<V<int>> a(h,V<int>(w));
    rep(i,h)rep(j,w) cin >> a[i][j];

    V<op> ops;
    int cur = 0;
    rep(i,h) {
        cur = 0;
        rep(j,w) {
            a[i][j] += cur;            
            if(j != 0 && cur) ops.push_back(op{i, j-1, i, j});
            cur = (a[i][j] % 2);
        }
    }

    cur = 0;
    rep(i,h) {
        a[i][w-1] += cur;
        if(i != 0 && cur) ops.push_back(op{i-1, w-1, i, w-1});
        cur = (a[i][w-1] % 2);
    }

    int ans = sz(ops);
    cout << ans << endl;
    rep(i,ans) {
        printf("%d %d %d %d\n", ops[i].x+1, ops[i].y+1, ops[i].x2+1, ops[i].y2+1);
    }

}