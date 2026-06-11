#include <bits/stdc++.h>
using namespace std;

#define REP(i,m,n) for(int i=(m); i<(int)(n); i++)
#define RREP(i,m,n) for(int i=(int)(n-1); i>=m; i--)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) RREP(i,0,n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define fi first
#define se second
#define debug(...) {cerr<<"[L"<<__LINE__<<"] "; _debug(__VA_ARGS__);}

template<typename T>
string join(const vector<T>&v, string del=", "){ stringstream s;
    for(auto x : v) s << del << x; return s.str().substr(del.size());
}
template<typename T>
ostream& operator<<(ostream& o, const vector<T>&v){
    if(v.size()) o << "[" << join(v) << "]"; return o;
}
template<typename T>
ostream& operator<<(ostream& o, const vector<vector<T> >&vv){
    int l = vv.size();
    if(l){ o<<endl; rep(i,l) o << (i==0 ? "[ " : ",\n  " ) << vv[i] << (i==l-1 ? " ]" : ""); }
    return o;
}
inline void _debug(){cerr<<endl;}
template<class First, class... Rest>
void _debug(const First& first, const Rest&... rest){cerr<<first<<" ";_debug(rest...);}

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

const double PI = (1*acos(0.0));
const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll mod = 1e9 + 7;

inline void finput(string filename) {
    freopen(filename.c_str(), "r", stdin);
}

struct UnionFind {
    int n;
    vector<int> dat;
    UnionFind(int size): n(size), dat(size, -1) { }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (dat[y] < dat[x]) swap(x, y);
            dat[x] += dat[y];
            dat[y] = x;
        }
        return x != y;
    }
    bool same(int x, int y){
        return root(x) == root(y);
    }
    int root(int x){
        return dat[x] < 0 ? x : dat[x] = root(dat[x]);
    }
    int size(int x){
        return -dat[root(x)];
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    // finput("./input");
    int n,m; cin >> n >> m;
    auto uf = UnionFind(n);
    rep(i,m){
        int x,y,z; cin >> x >> y >> z;
        uf.unite(x-1,y-1);
    }
    int ans = 0;
    rep(i,n){
        if(uf.root(i) == i) ans++;
    }
    cout << ans << endl;
    return 0;
}