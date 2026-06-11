#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define endl "\n"
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> c(n), d(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<int> dist(n, -1);
    dist[0] = 0;
    queue<int> que;
    que.push(0);
    while(que.size()) {
        int v = que.front();
        que.pop();
        if(dist[v] == -1) {
            continue;
        }
        for(auto u : g[v]) {
            if(dist[u] == -1) {
                dist[u] = dist[v] + 1;
                que.push(u);
            }
        }
    }

    sort(RALL(c));
    for(int i = 0; i < n; i++) {
        int id = min_element(ALL(dist)) - dist.begin();
        d[id] = c[i];
        dist[id] = INF;
    }
    cout << accumulate(ALL(c), -c[0]) << endl;
    for(int i = 0; i < n; i++) {
        cout << d[i] << ' ';
    }
    cout << endl;
}
