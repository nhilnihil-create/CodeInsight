#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define MOD (1000000007)
#define ALL(v) (v).begin(), (v).end()
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

//-------------------------------------

//二部グラフ判定。頂点をc(1か-1(黒か白))で塗る
bool dfs(vector<vector<int>> &graph, vector<int> &color, int v, int c)
{
    color[v] = c; //まず頂点vをcで塗る
    for (int i = 0; i < (int)graph[v].size(); i++)
    {
        // 隣り合う頂点が同じ色ならダメ
        if (color[graph[v][i]] == c)
        {
            return false;
        }
        // 隣り合う頂点がまだ塗られてないなら塗る
        if (color[graph[v][i]] == 0 && !dfs(graph, color, graph[v][i], -c))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n); //隣接リスト
    vector<int> color(n, 0);      //各頂点が何色か。黒=1, 白=-1、まだ塗られてない=0
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    if (dfs(graph, color, 0, 1))
    {
        ll b = count(ALL(color), 1);
        ll w = n - b;
        cout << b * w - m << endl;
    }
    else
    {
        ll a = (ll)n * (n - 1) / 2;
        cout << a - m << endl;
    }
}