#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }
//void chmin(int &a, int b) { if (a > b) a = b; }
//void chmax(int &a, int b) { if (a < b) a = b; }

const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

//重みある時
using Edge = pair<int,int>;
using Graph = vector<vector<Edge> >;

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
    int n,m;
    cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    UnionFind uf(n);
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        uf.merge(x-1,y-1);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(uf.issame(i,p[i]-1)) ans++;
    }
    cout << ans << endl;
    return 0;
}
