#include <bits/stdc++.h>
#define SIZE 300005
#define MOD 1000000007LL
#define EPS 1e-10
#define INF 1 << 29
#define LLINF 1LL << 60
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define DOWN(i,b,a) for(int i=b;i>=a;i--)
#define SET(a,c) memset(a,c,sizeof a)
#define BIT(i,j) ((i)>>(j))&1
#define ALL(o) (o).begin(), (o).end()
#define ERASE(o) (o).erase(unique((o).begin(),(o).end()), (o).end())
#define SQ(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> Pll;
typedef pair<int, int> Pii;
typedef pair<double, double> Pdd;
typedef complex<double> dcomplex;
template<typename T> inline void priv(vector<T>a){REP(i,a.size()){cerr<<a[i]<<((i==a.size()-1)?"\n":" ");}}
ll gcd(ll a,ll b){int c=max(a,b);int d=min(a,b);return c==0||d==0?c:gcd(c%d,d);}
ll lcm(ll a,ll b){return a==0||b==0?0:a*b/gcd(a,b);}
ll fact(ll a){ll b=1;FOR(i,1,a)b*=i;return b;}

ll N, M;

class UnionFind {
    public:
    vector<int> par;
    UnionFind(int n) : par(n) {
        for(int i = 0; i < n; i++) par[i] = i;
    }
    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }
    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    cin >> N >> M;
    vector<ll> p(N), x(M), y(M);
    REP(i, N) {
        cin >> p[i];
        p[i]--;
    }
    REP(i, M) {
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }
    UnionFind uf = UnionFind(N);    
    REP(i, M) {
        uf.unite(x[i], y[i]);
    }
    map<int, int> d;
    priv(p);
    priv(uf.par);
    REP(i, N) {
        int root = uf.root(i);
        if(d.find(uf.root(i)) == d.end()) d[root] = 0;
        if(uf.same(i, p[i])) d[root]++;
    }
    int ans = 0;
    for(auto p : d) ans += p.second;
    cout << ans << endl;
	return 0;
}
