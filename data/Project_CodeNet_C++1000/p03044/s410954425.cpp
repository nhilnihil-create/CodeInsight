#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

long long mod = 998244353;
#define REP(i, n) for (long long i = 0; i < (n); i++)

long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return t * t;
    } else {
        return modpow(m, n - 1) * m;
    }
}

long long moddiv(long long a, long long b) { return (a * modpow(b, mod - 2)) % mod; }

long long nCkmod(long long n, long long k) {
    long long denomi = 1;
    REP(i, n) {
        denomi *= (i + 1);
        denomi %= mod;
    }
    long long numera = 1;
    for (int i = n - k; i > 0; i--) {
        numera *= i;
        numera %= mod;
    }
    REP(i, k) {
        numera *= (i + 1);
        numera %= mod;
    }
    return moddiv(denomi, numera);
}

void print_binary(long long a) {
    for (int i = 31; i >= 0; i--) {
        cout << (a >> i & 1);
    }
    cout << endl;
}

void yes() {
    cout << "Yes" << endl;
    exit(0);
}
void no() {
    cout << "No" << endl;
    exit(0);
}
vector<long long> dijkstra(vector<vector<pair<long long, long long>>> graph, long long s) {
    vector<long long> ans(graph.size(), -1);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>
        pq;
    pq.push({0, s});
    while (pq.size() > 0) {
        int cur1 = 0;
        int cur2 = 0;
        if (ans[pq.top().second] != -1) {
            pq.pop();
        } else {
            cur1 = pq.top().first;
            cur2 = pq.top().second;
            pq.pop();
            ans[cur2] = cur1;
            for (long long i = 0; i < graph[cur2].size(); i++) {
                pq.push({cur1 + graph[cur2][i].second, graph[cur2][i].first});
            }
        }
    }
    return ans;
}
signed main() {
    int n;
    cin >> n;
    vector<vector<pair<long long, long long>>> graph(n);
    REP(i, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    vector<long long> dist;
    dist = dijkstra(graph, 0);
    REP(i, n) {
        if (dist[i] % 2 == 0) {
            //cout << dist[i] << endl;
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    }
}