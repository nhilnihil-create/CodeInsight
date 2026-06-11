#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <tuple>
#include <deque>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <utility>
#include <complex>
#include <functional>
using namespace std;
#define ALL(x) x.begin(), x.end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define debug(v)          \
    cout << #v << ":";    \
    for (auto x : v)      \
    {                     \
        cout << x << ' '; \
    }                     \
    cout << endl;
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}

////////////////////
int max_len;
struct DirectedGraph
{
    int V;

    vector<vector<int> > to;
    vector<vector<int> > from;

    vector<int> vs;
    vector<int> depth;
    vector<bool> used;
    vector<int> cmp; //cmp[点]=(トポソ後のその点の順位)

    void dfs(int v)
    {
        used[v] = true;
        for (auto t : to[v])
            if (!used[t])
                dfs(t);
        vs.push_back(v); //帰りがけ
    }
    //k:始点,rdfsがkに戻る→強連結成分
    int r_dfs(int v, int k)
    {
        int ret = 0;
        used[v] = true;
        cmp[v] = k;
        for (const auto t : from[v])
        {
            if (!used[t])
                r_dfs(t, k);
            depth[v] = max(depth[v], depth[t] + 1);
        }
    }
    DirectedGraph(int V) : V(V),
                           to(vector<vector<int> >(V)),
                           from(vector<vector<int> >(V)),
                           cmp(vector<int>(V)),
                           depth(vector<int>(V))
    {
    }

    void add_edge(int from_, int to_)
    {
        to[from_].push_back(to_);
        from[to_].push_back(from_);
    }

    //強連結成分:任意の2頂点を行き来できる部分グラフ
    //          1点だけのも競連結成分
    //順方向帰りがけdfsと逆方向行き止まりまでdfs
    //強連結成分分解O(|V|+|E|)
    int scc_num = -1;
    //scc_num:強連結成分の個数を返す
    int scc()
    {
        used = vector<bool>(V, false);
        vs.clear();
        for (int v = 0; v < V; v++)
            if (!used[v])
                dfs(v);
        used = vector<bool>(V, false);
        scc_num = 0;
        for (int i = vs.size() - 1; i >= 0; i--)
            if (!used[vs[i]])
            {
                max_len = max(max_len, r_dfs(vs[i], scc_num++));
            }
        return scc_num;
    }

    bool isCyclic()
    {
        //強連結成分が全部1点だけのものであれば
        //強連結成分の数は点数と一致し、閉路はない
        return (scc_num != V);
        //true:Dagじゃない
        //false:Dag
    }

    //sccの後潰してトポロジカル順序のグラフを作る
    DirectedGraph makeTopologicalGraph()
    {
        DirectedGraph TG(scc_num);
        rep(s, V) for (auto t : to[s])
        {
            if (cmp[s] != cmp[t])
                TG.add_edge(cmp[s], cmp[t]);
        }
        return TG;
    }
};
////////////////////////////////

int n, m;

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    DirectedGraph g(n);
    rep(i, m + n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g.add_edge(a, b);
    }
    g.scc();

    //トポソしたあと，点aの親は辺が生えてる中で一番順位が遅いやつ
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (g.from[i].empty())
        {
            ans[i] = -1;
            continue;
        }
        int par, rank = -1;
        for (auto x : g.from[i])
        {
            if (chmax(rank, g.cmp[x]))
            {
                par = x;
            }
        }
        ans[i] = par;
    }
    for (auto x : ans)
    {
        cout << x + 1 << endl;
    }
    return 0;
}
