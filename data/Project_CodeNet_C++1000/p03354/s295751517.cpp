#include <bits/stdc++.h>
#define rep(i, start, end) for (long long i = start; i < end; ++i)
#define repreverse(i, start, end) for (long long i = start; i >= end; --i)
#define all(x) (x).begin(), (x).end()
#define len(x) ((long long)(x).size())
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vllvll = vector<vll>;
using pll = pair<ll, ll>;
template<class T>void print1d(T x,ll n=-1){if(n==-1)n=x.size();rep(i,0,n){cout<<x[i]<<' ';}cout<<'\n';}
template<class T>void print2d(T x,ll r=-1,ll c=-1){if(r==-1)r=x.size();if(c==-1)c=x[0].size();rep(i,0,r)print1d(x[i],c);}
template<class T, class U>bool haskey(T mp, U key) { return mp.find(key) != mp.end(); }
template<class T, class U>bool isin(T el, U container) { return find(all(container), el) != container.end(); }
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template<class T>bool even(T n) { return ! (n & 1); }
template<class T>bool odd(T n) { return n & 1; }
template<class T>ld deg2rad(T deg) { return M_PI * deg / 180.0; }
template<class T>ld rad2deg(T rad) { return 180.0 * rad / M_PI; }
ll intpow(ll a,ll n){ll p=1;while(n){if(n&1)p*=a;a*=a;n>>=1;}return p;}
const long double pi = M_PI;
const long long big = 1LL << 50;
const long long inf = 1LL << 60;
const long long mod = 1e9 + 7;

class UnionFind
{   
public:
    static const int N_MAX = 1000000;
    int par[N_MAX];
    int sz[N_MAX];
    int n;
    
    UnionFind(int n)
        : n{n}
    {
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            sz[i] = 1;
        }
    }
    
    void init()
    {
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int root(int x)
    {
        if (par[x] == x) {
            return x;
        }
        return par[x] = root(par[x]);
    }
    
    bool same(int x, int y)
    {
        return root(x) == root(y);
    }
    
    void unite(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) {
            return;
        }
        if (sz[rx] > sz[ry]) {
            par[ry] = rx;
            sz[rx] += sz[ry];
        } else {
            par[rx] = ry;
            sz[ry] += sz[rx];
        }
        return;
    }

    int size(int x)
    {
        return sz[root(x)];
    }
    
    int groups()
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (root(i) == i)
            ++cnt;
        }
        return cnt;
    }
};


int main()
{
        ll N, M;
        cin >> N >> M;
        vll p(N);
        rep(i, 0, N) cin >> p[i];

        UnionFind uf(N);
        rep(i, 0, M) {
                ll x, y;
                cin >> x >> y;
                uf.unite(x, y);
        }

        ll ans = 0;
        rep(i, 1, N+1) {
                if (uf.same(i, p[i-1])) ++ans;
        }
        cout << ans << endl;
}