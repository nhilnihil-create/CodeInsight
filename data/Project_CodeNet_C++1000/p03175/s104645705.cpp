#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<ull> vul;
#define For(i, n) for(ll i = 0; i < n; i++)
#define len(n) (ll)(n).size()
#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define Sort(a) sort(a.begin(), a.end())

vector<vl> graph;
vector<bool> used;
ll dp[(ll)1e5][2];

pair<ll, ll> dfs(ll v) {
    used[v] = true;
    dp[v][0] = 1;
    dp[v][1] = 1;
    for (ll to : graph[v]) {
        if (!used[to]) {
            auto q = dfs(to);
            dp[v][0] = (dp[v][0] * (q.first + q.second)) % ((ll)1e9 + 7);
            dp[v][1] = (dp[v][1] * q.first) % ((ll)1e9 + 7);
        }
    }
    return { dp[v][0], dp[v][1] };
}

int main() {
    FAST_IO;
    ll N;
    cin >> N;
    graph.resize(N);
    used.resize(N);
    For(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    auto q = dfs(0);
    cout << (q.first + q.second) % ((ll)1e9 + 7) << '\n';
    return 0;
}