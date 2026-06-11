#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using vec = vector<ll>;
using vect = vector<double>;
using Graph = vector<vector<ll>>;
#define loop(i, n) for (ll i = 0; i < n; i++)
#define Loop(i, m, n) for (ll i = m; i < n; i++)
#define pool(i, n) for (ll i = n; i >= 0; i--)
#define Pool(i, m, n) for (ll i = n; i >= m; i--)
#define mod 1000000007ll
//#define mod 998244353ll
#define flagcount __builtin_popcount
#define flag(x) (1 << x)
#define flagadd(bit, x) bit |= flag(x)
#define flagpop(bit, x) bit &= ~flag(x)
#define flagon(bit, i) bit &flag(i)
#define flagoff(bit, i) !(bit & (1 << i))
#define all(v) v.begin(), v.end()
#define low2way(v, x) lower_bound(all(v), x)
#define high2way(v, x) upper_bound(all(v), x)
#define idx_lower(v, x) (distance(v.begin(), low2way(v, x)))  //配列vでx未満の要素数を返す
#define idx_upper(v, x) (distance(v.begin(), high2way(v, x))) //配列vでx以下の要素数を返す
#define idx_lower2(v, x) (v.size() - idx_lower(v, x))         //配列vでx以上の要素数を返す
#define idx_upper2(v, x) (v.size() - idx_upper(v, x))         //配列vでxより大きい要素の数を返す
#define putout(a) cout << a << endl
#define Gput(a, b) G[a].push_back(b)
#define Sum(v) accumulate(all(v), 0ll)
#define gcd(x, y) __gcd(x, y)
ll ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return 0;
}
template <typename T>
T lcm(T x, T y)
{
    T z = gcd(x, y);
    return x * y / z;
}
template <typename T>
bool primejudge(T n)
{
    if (n < 2)
        return false;
    else if (n == 2)
        return true;
    else if (n % 2 == 0)
        return false;
    double sqrtn = sqrt(n);
    for (T i = 3; i < sqrtn + 1; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}
//場合によって使い分ける
//const ll dx[4]={1,0,-1,0};
//const ll dy[4]={0,1,0,-1};
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//2次元配列の宣言
//vector<vector<ll>> field(h, vector<ll>(w));
//無向グラフの木の直径を求める(重みなしなら辺のcostを1に)
struct edge
{
    long long to;
    long long cost;
    edge(long long t, long long c) : to(t), cost(c) {}
};
pair<long long, long long> dia_dfs(const vector<vector<edge>> &G, long long v, long long par)
{
    pair<long long, long long> ret = make_pair(0, v);
    for (auto e : G[v])
    {
        long long nv = e.to;
        if (nv == par)
            continue;
        auto next = dia_dfs(G, nv, v);
        next.first += e.cost;
        ret = max(ret, next);
    }
    return ret;
}
long long tree_diameter(const vector<vector<edge>> &G)
{
    auto p = dia_dfs(G, 0, -1), q = dia_dfs(G, p.second, -1);
    return q.first;
}
//木の直径の端点の組の1つを返す(0-indexed)
pair<long long, long long> tree_end_nodes(const vector<vector<edge>> &G)
{
    auto p = dia_dfs(G, 0, -1), q = dia_dfs(G, p.second, -1);
    return make_pair(p.second, q.second);
}
int main()
{
    cout << fixed << setprecision(30);
    ll n;
    cin >> n;
    vector<vector<edge>> G(n);
    loop(i, n - 1)
    {
        ll s, t;
        cin >> s >> t;
        s--;
        t--;
        G[s].push_back(edge(t, 1));
        G[t].push_back(edge(s, 1));
    }
    ll dia = tree_diameter(G);
    if (dia % 3 == 1)
        putout("Second");
    else
        putout("First");
    return 0;
}
