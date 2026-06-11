
#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(ll a = 0;a < n;a++)

static const ll INF = 1e15;
static const ll mod = 1e9+7;

template<typename T>
static inline void chmin(T& ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
    if (ref < value) ref = value;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<vector<int>> rev(n+1);
    rep(i, n + m - 1) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        rev[b].push_back(a);
    }
    vector<map<int,int>> visit(n+1);
    vector<int> distance(n+1, 0);
    int root = -1;
    for (int i = 1; i <= n;i++) {
        if (rev[i].size() == 0) {
            root = i;
            break;
        }
    }
    vector<int> parents(n+1, -1);
    function<void(int, int, int)> dfs = [&](int current, int from, int dist) {
        visit[current][from] = dist;
        if (visit[current].size() == rev[current].size()) {
            int u = 0;
            int par = -1;
            for (auto p : visit[current]) {
                if (u < p.second) {
                    par = p.first;
                    u = p.second;
                }
            }
            distance[current] = u;
            parents[current] = par;
            for (auto next : graph[current]) {
                dfs(next, current, u + 1);
            }
        }
    };
    parents[root] = 0;
    distance[root] = 0;
    for (auto next : graph[root]) {
        dfs(next, root, 1);
    }
    for (int i = 1; i <= n; i++) {
        cout << parents[i] << endl;
    }
    return 0;
}
