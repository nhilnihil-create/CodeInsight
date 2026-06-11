#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <climits>
#include <cstdint>
using namespace std;

inline namespace atcoder {
    template <typename T, size_t Depth>
    struct vector_helper { using type = vector<typename vector_helper<T, Depth - 1>::type>; };
    template <typename T>
    struct vector_helper<T, 0> { using type = T; };
    template <typename T, size_t Depth>
    using vector_t = typename vector_helper<T, Depth>::type;

    template <typename T> using vec = vector_t<T, 1>;
    template <typename T> using vvec = vector_t<T, 2>;
    template <typename T> using vvvec = vector_t<T, 3>;
}

void dfs(int v, vec<bool> &visited, vvec<bool> &graph) {
    visited[v] = true;
    for (int i = 0; i < graph[v].size(); ++i) {
        if (!graph[v][i]) continue;
        if (visited[i]) continue;
        dfs(i, visited, graph);
    }
}

int main() {
    int n, m; cin >> n >> m;

    vvec<bool> graph(n, vec<bool>(n, false));
    vec<array<int, 2>> edge(m);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        graph[a][b] = graph[b][a] = true;
        edge[i][0] = a; edge[i][1] = b;
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        graph[edge[i][0]][edge[i][1]] = graph[edge[i][1]][edge[i][0]] = false;
        vec<bool> visited(n, false);

        dfs(0, visited, graph);

        bool bridge = false;
        for (auto e : visited) {
            if (!e) {
                bridge = true;
            }
        }

        if (bridge) {
            ++ans;
        }

        graph[edge[i][0]][edge[i][1]] = graph[edge[i][1]][edge[i][0]] = true;
    }

    cout << ans << endl;
}

