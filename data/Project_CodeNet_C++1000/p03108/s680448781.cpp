#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }
};

int main() {
    ll n,m;
    ll ans = 0;
    cin >> n >> m;
    ans = n*(n-1)/2;
    UnionFind uf(n);
    vector<int> a(m),b(m);
    vector<ll> ansv;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        a[i]--,b[i]--;
    }
    for (int i = 0; i < m; ++i) {
        ansv.push_back(ans);
        if(!uf.issame(a[m-1-i],b[m-1-i])){
            ans -= uf.size(a[m-1-i])*uf.size(b[m-1-i]);
            uf.merge(a[m-1-i],b[m-1-i]);
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << ansv[m-1-i] << endl;
    }
    return 0;
}