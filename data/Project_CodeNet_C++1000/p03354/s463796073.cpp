#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
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

// union-find
struct union_find {
    vector<int> data;

    union_find(int size) {data.resize(size,-1);}

    int find(int x) {
        if (data[x] < 0) {return x;}
        return data[x] = find(data[x]);
    }

    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) {return false;}
        if (data[x] > data[y]) swap(x,y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int size(int x) {return -data[x];}
};

int main() {
    int n, m; cin >> n >> m;
    vint p(n);
    rep(i,n) cin >> p[i];
    union_find uf(n);
    rep(i,m) {
        int a, b; cin >> a >> b;
        a--; b--;
        uf.unite(a,b);
    }
    int ans = 0;
    rep(i,n) {
        if (uf.find(i) == uf.find(p[i]-1)) ans++;
    }
    cout << ans << endl;
}