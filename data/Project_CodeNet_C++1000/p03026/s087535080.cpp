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

vector<vector<int>> edge;
vector<int> c;
vector<int> result;
vector<bool> isVisited;

int dfs(int node, int offset)
{
    isVisited[node] = true;

    rep(i, edge[node].size())
    {
        int child = edge[node][i];
        if (!isVisited[child]) {
            offset = dfs(child, offset);
        }
    }
    result[node] = c[offset];
    return offset + 1;
}

int main()
{
    int n;
    cin >> n;

    edge.resize(n);
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    c.resize(n);
    rep(i, n)
    {
        cin >> c[i];
    }
    sort(c.begin(), c.end());

    int score = 0;
    rep(i, n - 1)
    {
        score += c[i];
    }

    result.resize(n);
    isVisited.resize(n);
    fill(isVisited.begin(), isVisited.end(), false);
    dfs(0, 0);

    cout << score << endl;
    rep(i, n)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}