#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <random>
#include <functional>

using namespace std;

const int N = 2e5 + 7;

int n;
vector<int> a;

int fnd = 0;
int used[4 * N];
vector<int> ng[4 * N];

int new_state(int v, int x) {
    return 4 * v + x;
}

void add_edge(int v, int xv, int u, int xu) {
    ng[new_state(v, xv)].push_back(new_state(u, xu));
}

void dfs(int cur) {
    used[cur] = 1;
    for (auto t : ng[cur]) {
        if (used[t] == 1) {
            fnd = 1;
        }
        if (!used[t]) {
            dfs(t);
        }
    }
    used[cur] = 2;
}

int solve() {
    for (int i = 0; i < 4 * n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    return fnd;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        a.push_back(c == 'A');
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> nd = {0, 0, 1, 1};
    for (int i = 0; i < n; i++) {
        for (auto t : g[i]) {
            for (int f = 0; f < 4; f++) {
                for (int s = 0; s < 4; s++) {
                    if (nd[f] == a[i] && nd[s] == a[t] && (f + 1) % 4 == s) {
                        add_edge(i, f, t, s);
                    }
                }
            }
        }
    }
    if (solve()) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}   
