#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using Graph = std::vector<std::vector<ll>>;

enum Color : uint8_t {
    Unvisited, Black, White
};

ll N, M;
Graph graph;
std::vector<Color> colors;


bool dfs(const ll index, const Color color) {
    colors[index] = color;

    for (const auto &next : graph[index]) {
        if (colors[next] != Unvisited) {
            if (color == colors[next]) { return false; } else { continue; }
        }

        if (!dfs(next, color == Black ? White : Black)) { return false; }
    }

    return true;

}

int main() {
    cin >> N >> M;

    graph.resize(N);

    {
        ll a, b;
        for (ll i = 0; i < M; ++i) {
            cin >> a >> b;
            graph[a - 1].push_back(b - 1);
            graph[b - 1].push_back(a - 1);
        }
    }

    colors.assign(N, Unvisited);

    bool is_bipartite = true;
    for (ll i = 0; i < N; ++i) {
        if (colors[i] != Unvisited) { continue; }
        if (!dfs(i, White)) {
            is_bipartite = false;
        }
    }

    if (is_bipartite) {
        const auto num_white = std::count(colors.cbegin(), colors.cend(), White);
        const auto num_black = N - num_white;
        cout << num_white * num_black - M << endl;
    } else {
        cout << N * (N - 1) / 2 - M << endl;
    }

    return 0;
}