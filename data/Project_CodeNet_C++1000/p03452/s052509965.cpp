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

const int Maxn = 100010;
const ll INF = (ll) 1e10;

vector<edge> g[Maxn];
ll dist[Maxn];

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int l, r;
        ll d;
        cin >> l >> r >> d;
        l--, r--;
        g[l].emplace_back(r, d);
        g[r].emplace_back(l, -d);
    }
    fill(dist, dist + n, INF);
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            queue<int> que;
            que.push(i);
            dist[i] = 0;
            while (!que.empty()) {
                int p = que.front();
                que.pop();
                for(auto &v : g[p]){
                    if (dist[v.to] == INF){
                        dist[v.to] = dist[p] + v.cost;
                        que.push(v.to);
                    }else if (dist[v.to] != dist[p] + v.cost){
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Yes" << endl;
}
