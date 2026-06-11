#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

//UnionFind
// グラフを保持する必要はない。このままはっつけていける
// 計算量はほぼ定数とみなせる
struct UnionFind
{
    vector<int> d;
    UnionFind(int n = 0) : d(n, -1) {}
    int root(int x)
    {
        if (d[x] < 0)
            return x;
        return d[x] = root(d[x]);
    }
    // 辺情報から2点をくっつける
    bool unite(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
        {
            return false;
        }
        if (-d[x] < -d[y])
            swap(x, y); //y.size()が小でx.size()が大にしておきたい
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -d[root(x)]; }
};
//
int main()
{
    int n,m;cin >> n >> m;
    vector<int> p(n+1);
    for (int i = 1; i < n+1; i++)
    {
        cin >> p[i];
    }
    vector<P> sousa(m);rep(i,m) cin >> sousa[i].first >> sousa[i].second;
    UnionFind uf(n+1);
    rep(i,m)
    {
        uf.unite(sousa[i].first, sousa[i].second);
    }
    int counter = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if(uf.same(i, p[i]))counter++;
    }
    cout << counter << endl;
}