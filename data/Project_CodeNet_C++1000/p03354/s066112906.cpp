#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;
using vpii = vector<pair<int, int>>;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep1(i, n) for (int i = 1; i < (int)n; i++)
const ll mod = 1e9 + 7;
const ll inf = 1e12;
const double pi = 3.141592;
const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};

struct UnionFind
{
    vector<int> par;

    UnionFind(int N) : par(N)
    {
        for (int i = 0; i < N; i++)
        {
            par[i] = i;
        }
    }

    int root(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry)
            return;
        par[rx] = ry;
    }

    bool same(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> p(n+1);
    rep(i, n) cin >> p[i+1];
    UnionFind u(n+1);
    rep(i,m){
        int x, y;
        cin >> x >> y;
        u.unite(x, y);
    }
    int ans = 0;
    rep1(i, n+1)
    {
        if(i==p[i] || u.same(i,p[i])){
            ++ans;
            continue;
        }
    }
    cout << ans << "\n";
    return 0;
}