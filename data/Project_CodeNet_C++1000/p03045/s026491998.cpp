#include <bits/stdc++.h>
#define rep(i, start, end) for (long long i = start; i < end; ++i)
#define all(x) (x).begin(), (x).end()
#define len(x) ((long long)(x).size())
#define g(a, b) __gcd((a), (b))
#define l(a, b) ((a) / __gcd((a), (b)) * (b))
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vllvll = vector<vll>;
using pll = pair<ll, ll>;
template<class T>void print1d(T x,ll n=-1){if(n==-1)n=x.size();rep(i,0,n){cout<<x[i]<<' ';}cout<<'\n';}
template<class T>void print2d(T x,ll r=-1,ll c=-1){if(r==-1)r=x.size();if(c==-1)c=x[0].size();rep(i,0,r)print1d(x[i],c);}
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template<class T, class U>T rem(T a, U b) { return a - b*floor(a/b); }
template<class T>ld deg2rad(T deg) { return M_PI * deg / 180.0; }
template<class T>ld rad2deg(T rad) { return 180.0 * rad / M_PI; }
const long double pi = M_PI;
const long long big = 1LL << 50;
const long long inf = 1LL << 60;
const long long mod = 1e9 + 7;

class UnionFind
{   
public:
    static const int N_MAX = 1000000;
    int par[N_MAX];
    int n;
    
    UnionFind(int n)
        : n{n}
    {
        for (int i = 0; i < n; ++i) {
            par[i] = i;
        }
    }
    
    void init()
    {
        for (int i = 0; i < n; ++i) {
            par[i] = i;
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
        par[ry] = root(x);
        return;
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
        UnionFind uf(N);
        rep(i, 0, M) {
                ll x, y, z;
                cin >> x >> y >> z;
                uf.unite(x-1, y-1);
        }
        cout << uf.groups() << endl;
}