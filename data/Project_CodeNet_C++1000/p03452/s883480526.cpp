#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <climits>

typedef long vertex;
typedef long dist;

using namespace std;

vector<bool> data_exists;
vector<long> xs;

long n;
long m;

vector<vertex> ls;
vector<vertex> rs;
vector<dist> ds;

map<vertex, vector<pair<vertex,dist>>> adj_map;

bool dfs(vertex v) {
    for (auto&& pair : adj_map[v]) {
        vertex w = pair.first;
        dist d = pair.second;
        if (data_exists[w]) {
            if (xs[w] != xs[v] + d) return false;
        } else {
            data_exists[w] = true;
            xs[w] = xs[v] + d;
            if (!dfs(w)) return false;
        }
    }
    return true;
}

bool solve() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    data_exists.resize((unsigned long)n, false);
    xs.resize((unsigned long)n);

    for (int i = 0; i < m; i++) {
        vertex l, r;
        dist d;
        cin >> l >> r >> d;
        l--;
        r--;
        adj_map[l].emplace_back(make_pair(r, d));
        adj_map[r].emplace_back(make_pair(l, -d));
    }

    for (vertex v = 0; v < n; v++) {
        if (!data_exists[v]) {
            xs[v] = 0;
            if (!dfs(v)) return false;
        }
    }
    return true;
}

int main() {
    cout << (solve() ? "Yes" : "No");
    return 0;
}