#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> in(n, -1);
    vector<int> up(n, n + 123);
    int idx = 0;
    int res = 0;
    function<void(int,int)> dfs = [&](int u, int p) {
        in[u] = ++idx;
        up[u] = in[u];
        for (auto v : graph[u]) {
            if (v == p) {
                continue;
            }

            if (in[v] >= 0) {
                up[u] = min(up[u], in[v]);
            } else {
                dfs(v, u);
                up[u] = min(up[u], up[v]);
                if (up[v] > in[u]) {
                    ++res;
                }
            }
        }
    };

    dfs(0, -1);

    cout << res << '\n';



    return 0;
}