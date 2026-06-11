#include <algorithm>
#include <cmath>
#include <functional>
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

vector<vector<int>> neighbor;

void dfs(int node, int d, vector<int>& dist, vector<bool>& isVisited)
{
    isVisited[node] = true;
    dist[node] = d;

    for (int ch : neighbor[node]) {
        if (!isVisited[ch]) {
            dfs(ch, d + 1, dist, isVisited);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    neighbor.resize(n);
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        neighbor[a].push_back(b);
        neighbor[b].push_back(a);
    }

    vector<int> dist(n);
    vector<bool> isVisited(n, false);
    dfs(0, 0, dist, isVisited);
    int d = 0, v = 0;
    rep(i, n)
    {
        if (d < dist[i]) {
            d = dist[i];
            v = i;
        }
    }

    fill(isVisited.begin(), isVisited.end(), false);
    dfs(v, 0, dist, isVisited);
    int diameter = 0;
    rep(i, n)
    {
        diameter = max(diameter, dist[i]);
    }

    if ((diameter + 1) % 3 == 2) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }

    return 0;
}