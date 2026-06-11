#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

struct Edge
{
    int to;
};

using Graph = vector<vector<Edge>>;
using P = pair<long, long>;

/* Lowlink: グラフの関節点・橋を列挙する構造体
    作成 : O(E+V)
    関節点の集合 : vector<int> aps
    橋の集合 : vector<P> bridges
    */
struct Lowlink
{
    const Graph &G;
    vector<int> used, ord, low;
    vector<int> aps; // articlation points
    vector<P> bridges;

    Lowlink(const Graph &G_) : G(G_)
    {
        used.assign(G.size(), 0);
        ord.assign(G.size(), 0);
        low.assign(G.size(), 0);
        int k = 0;
        for (int i = 0; i < (int)G.size(); i++)
        {
            if (!used[i])
                k = dfs(i, k, -1);
        }
        sort(aps.begin(), aps.end());
        sort(bridges.begin(), bridges.end());
    }

    int dfs(int id, int k, int par)
    { // id:探索中の頂点, k:dfsで何番目に探索するか, par:idの親
        used[id] = true;
        ord[id] = k++;
        low[id] = ord[id];
        bool is_aps = false;
        int count = 0; //子の数
        for (auto &e : G[id])
        {
            if (!used[e.to])
            { // 子が探索済みかチェック
                count++;
                k = dfs(e.to, k, id);
                low[id] = min(low[id], low[e.to]); // 先と同じlow
                if (par != -1 && ord[id] <= low[e.to])
                    is_aps = true;
                if (ord[id] < low[e.to])
                    bridges.emplace_back(min(id, e.to), max(id, e.to));
            }
            else if (e.to != par) // さっき通ったところとかだと弾かれる
            {                     // eが後退辺の時(dfsでさきっぽまで到達)
                low[id] = min(low[id], ord[e.to]);
            }
        }
        if (par == -1 && count >= -2)
            is_aps = true;
        if (is_aps)
            aps.push_back(id);
        return k;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    int a, b;
    Edge ea, eb;
    rep(i, m)
    {
        cin >> a >> b;
        a--;
        b--;
        ea.to = a;
        eb.to = b;
        G[a].push_back(eb);
        G[b].push_back(ea);
    }
    Lowlink out(G);
    cout << out.bridges.size() << endl;

    return 0;
}