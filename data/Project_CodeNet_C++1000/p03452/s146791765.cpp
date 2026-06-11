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

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> graph(n);

    for (int i = 0; i < m; ++i) {
        int l, r, d;
        cin >> l >> r >> d;
        --l, --r;
        graph[l].emplace_back(r, d);
        graph[r].emplace_back(l, -d);
    }


    vector<bool> visited(n, false);
    const long long INF = 1LL << 50;
    vector<long long> dis(n, INF);
    vector<int> que(n + 123);

    bool ok = true;

    long long LIMIT = 1e9;
    for (int i = 0; i < n && ok; ++i) {
        if (visited[i]) {
            continue;
        }

        int s = i;
        int sz = 0;
        que[sz++] = s;
        visited[s] = true;
        dis[s] = 0;

        for (int j = 0; j < sz && ok; ++j) {
            int u = que[j];
            for (auto& e : graph[u]) {
                int v = e.first;
                long long w = e.second;
                long long d = dis[u] + w;
                if (!visited[v]) {
                    visited[v] = true;
                    dis[v] = d;
                    que[sz++] = v;
                } else {
                    if (d != dis[v]) {
                        ok = false;
                        break;
                    }
                }
            }
        }

        long long mn = INF;
        long long mx = -INF;
        for (int j = 0; j < sz; ++j) {
            int v = que[j];
            mn = min(mn, dis[v]);
            mx = max(mx, dis[v]);
        }
        if ((mx - mn) > LIMIT) {
            ok = false;
        }
    }

    if (!ok) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }


    return 0;
}