#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

using P = pair<int, int>;
vector<vector<int>> edge;
void dfs(int node, vector<int>& height, vector<bool>& isVisited, vector<P>& parent)
{
    isVisited[node] = true;
    height[node] = 0;

    rep(i, edge[node].size())
    {
        int nx = edge[node][i];
        if (!isVisited[nx]) {
            dfs(nx, height, isVisited, parent);
        }

        height[node] = max(height[node], height[nx] + 1);
    }

    rep(i, edge[node].size())
    {
        int nx = edge[node][i];
        P p = make_pair(height[node] - height[nx], node);
        parent[nx] = min(parent[nx], p);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<bool> isRoot(n, true);
    edge.resize(n);
    rep(i, n + m - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        edge[a].push_back(b);
        isRoot[b] = false;
    }

    int root;
    rep(i, n)
    {
        if (isRoot[i]) {
            root = i;
        }
    }

    vector<int> height(n, 0);
    vector<bool> isVisited(n, false);
    vector<P> parent(n, make_pair(n + 1, -1));
    dfs(root, height, isVisited, parent);

    rep(i, n)
    {
        int pnode;
        tie(ignore, pnode) = parent[i];
        cout << pnode + 1 << endl;
    }

    return 0;
}