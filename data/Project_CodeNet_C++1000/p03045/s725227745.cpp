#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;i<(n);i++)
#define REP(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define MOD 1000000007
#define INF 1e18
#define fcout cout << fixed << setprecision(15)
#define int long long
#define endl "\n"
#define yorn(f) puts((f)?"Yes":"No")
#define YORN(f) puts((f)?"YES":"NO")
typedef long long ll;
typedef pair<int, int> P;
int gcd(int a,int b){return b?gcd(b,a%b):a;};
int lcm(int a,int b){return a/gcd(a,b)*b;};
int mod(int a,int b){return (a+b-1)/b;};
template<typename A, size_t N, typename T>
void Fill(A(&array)[N],const T &val){std::fill((T*)array,(T*)(array+N),val);}
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;};
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;};

class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }

    // Member Function
    // Find
    ll root(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool unite(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool same(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }

    ll getsize(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }
};

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    int x[M], y[M], z[M];
    rep(i, M) {
        cin >> x[i] >> y[i] >> z[i];
        x[i]--; y[i]--;
    }

    UnionFind ut(N);
    rep(i, M) {
        ut.unite(x[i], y[i]);
    }
    set<int> st;
    rep(i, N) {
        st.insert(ut.root(i));
    }
    cout << st.size() << endl;
    return 0;
}