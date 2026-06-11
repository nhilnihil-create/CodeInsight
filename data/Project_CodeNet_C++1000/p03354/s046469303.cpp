#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
int const INF = 1001001001;

struct UnionFind
{
    vector<int> par; //par[i]:= iの親の番号
    vector<int> siz; //siz[i]:= iの属する連結成分の大きさ
    UnionFind(int N) {
        par.resize(N);
        for(int i = 0; i < N; ++i) {
            par[i] = i;
        }
        siz.resize(N,1);
    }

    int root(int x){ // xが属する木の根を再帰で得る：root(x) = {xの木の根}
    if(par[x] == x) return x;
    else return par[x] = root(par[x]);
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        return root(x) == root(y);
    }

    bool unite (int x, int y) { // xとyの木を併合
        x = root(x); y = root(y);
        if (x == y) return false;
 
        if (siz[x] < siz[y]) swap(x, y); // merge technique 小を大にくっつける
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    int size(int x) { // xの属する木の大きさを得る
        return siz[root(x)];
    }
};


int main()
{
    int n,m;
    cin >> n >> m;
    vi p(n);
    rep(i,n) cin >> p[i], p[i]--;

    UnionFind uf(n);
    rep(j,m) {
        int x,y;
        cin >> x >> y;
        x--; y--;
        uf.unite(x, y);
    }
    int res = 0;
    rep(i,n) {
        if(uf.same(p[i], i)) res++;
    }
    cout << res << endl;
    return 0;
}