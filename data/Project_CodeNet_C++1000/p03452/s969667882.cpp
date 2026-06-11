#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[] = {1, 0, -1, 0, 0};
const int dy[] = {0, 1, 0, -1, 0};

const int Maxn = 100010;
const int INF = (int) 1e9;

class edge {
public:
    int from, to;
    ll cost;

    edge(int t, ll c) : from(-1), to(t), cost(c) {}

    edge(int f, int t, ll c) : from(f), to(t), cost(c) {}

    bool operator<(const edge &e) const {
        return cost < e.cost;
    }

    bool operator>(const edge &e) const {
        return cost > e.cost;
    }
};

int n, m;

vector<vector<edge>> g;
int d[Maxn];

bool ng;

void dfs(int i){
    for (auto &e : g[i]) {
        if (d[e.to] == INF){
            d[e.to] = d[i] + e.cost;
            dfs(e.to);
        }else if (d[e.to] != d[i] + e.cost){
            ng = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int l, r, c;
        cin >> l >> r >> c;
        l--, r--;
        g[l].emplace_back(r, c);
        g[r].emplace_back(l, -c);
    }

    fill(d, d + n, INF);
    for (int i = 0; i < n; ++i) {
        if (d[i] == INF) {
            d[i] = 0;
            ng = false;
            dfs(i);
            if (ng) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
