#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for (int i = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define MP make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int MOD = 1e9 + 7;

//UnionFind
struct UnionFind
{
    vector<ll> par;
    vector<ll> siz;

    UnionFind(ll N) : par(N), siz(N, 1LL)
    {
        for (int i = 0; i < N; i++)
            par[i] = i;
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
        if (siz[rx] < siz[ry])
            swap(rx, ry);
        siz[rx] += siz[ry];
        par[ry] = rx;
    }
    bool same(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    ll size(ll x)
    {
        return siz[root(x)];
    }
};

int main()
{
    int N;
    cin >> N;
    vector<int> P(N);
    rep(i, N) cin >> P[i];
    UnionFind uf(N + 1);
    set<int> se;
    rep(i, N)
    {
        if (se.count(P[i] - 1))
        {
            uf.unite(P[i] - 1, P[i]);
        }
        se.insert(P[i]);
    }
    ll ma = 0;
    FOR(i, 1, N + 1)
    {
        ma = max(uf.size(i), ma);
    }
    cout << N - ma << endl;
    return 0;
}