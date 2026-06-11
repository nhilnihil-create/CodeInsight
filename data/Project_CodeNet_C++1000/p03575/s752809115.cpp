#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define bitsz(x) int(__builtin_popcount(x))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(x) push_back(x)
#define INF 1e9
#define LINF 1e18
#define mod 1000000007
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
const int di[4] = {1,0,-1,0};
const int dj[4] = {0,1,0,-1};

struct UnionFind {
    //自身が親であれば，その集合に属する頂点数に-1を掛けたもの
    //そうでなければ親のid
    vector<int> r;

    UnionFind(int n) {
        r = vector<int>(n, -1);
    }

    int root(int x) { //木の根を調べる（どのグループに属しているか）
        if (r[x] < 0) return x;
        return r[x] = root(r[x]);
    }

    bool unite(int x, int y) { //xとyの属する集合を併合
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x, y);
        r[x] += r[y];
        r[y] = x;
        return true;
    }

    int size(int x) { //xが属する集合の頂点数を調べる
        return -r[root(x)];
    }

    bool same(int x, int y) { //xとyが同じ集合に属するか否か
        return root(x) == root(y);
    }
};

int main() {
    int n,m; cin >> n >> m;
    int ans = 0;
    vector<int> a(m),b(m);
    rep(i,m) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }

    rep(i,m) { //i番目の辺を消す
        UnionFind UF(n);
        rep(j,m) {
            if (j==i) continue;
            UF.unite(a[j],b[j]);
        }
        rep(j,n-1) {
            if (!UF.same(0,j+1)) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}