#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

const int INF = 1e9;
const long long LINF = 1e18;
const double PI=3.14159265358979323846;

typedef priority_queue<int, vector<int>, greater<int>> priority_queue_asc;

typedef vector<vector<int>> Graph;

void warhsall_floyd(Graph& G) {
    for (int k = 0; k < G.size(); k++) {
        for (int i = 0; i < G.size(); i++) {
            if (G[i][k] == INF) {
                continue;
            }
            for (int j = 0; j < G.size(); j++) {
                if (G[k][j] == INF) {
                    continue;
                }
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}

int main() {
    int H, W;
    cin >> H >> W;

    Graph g(10, vector<int>(10, 0));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int cij;
            cin >> cij;
            g[i][j] = cij;
        }
    }

    warhsall_floyd(g);

    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int Aij;
            cin >> Aij;
            if (Aij != -1) {
                ans += g[Aij][1];
            }
        }
    }

    cout << ans << endl;

    return 0;
}
