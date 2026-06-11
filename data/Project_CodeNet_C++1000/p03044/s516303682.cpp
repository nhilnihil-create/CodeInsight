#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <iterator>
#include <set>
#include <queue>
#include <bitset>
#include <cassert>

using namespace std;

struct Edge {
    int to;
    int weight;

    Edge(int to, int weight) : to(to), weight(weight) {}
};

using Graph = vector<vector<Edge>>;
vector<int> colors;
vector<bool> seen;

Graph graph;

void dfs(int v, int c) {
    seen[v] = true;
    colors[v] = c;
    for (auto e : graph[v]) {
        if (seen[e.to]) continue;
        if (e.weight % 2 != 0) {
            int t = 1- c;
            dfs(e.to, t);
        }
        else {
            dfs(e.to, c);
        }
    }
}

int main() {

    int N;
    cin >> N;

    graph.assign(N, vector<Edge>());
    seen.assign(N,false);
    colors.assign(N, 0);

    for (int i = 0; i < N - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u -= 1;
        v -= 1;
        graph[u].push_back(Edge(v, w));
        graph[v].push_back(Edge(u, w));
    }

    dfs(0, 1);

    for (int i = 0; i < N; ++i) {
        cout << colors[i] << endl;
    }

}