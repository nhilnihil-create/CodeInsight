#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

void dfs(const vector<vector<int>>& graph, const vector<ll>& c, vector<ll>& ans, int node, int parent, int& idx) {
    for (auto& next_node : graph[node]) {
        if (next_node == parent) {
            continue;
        }
        dfs(graph, c, ans, next_node, node, idx);
    }
    ans[node] = c[idx++];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<int>> graph(N);
    int a, b;
    rep(i, 0, N - 1) {
        cin >> a >> b;
        --a, --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<ll> C(N);
    for (auto& c : C) {
        cin >> c;
    }
    sort(all(C));
    ll sum = 0;
    rep(i, 0, N - 1) {
        sum += C[i];
    }
    cout << sum << endl;
    vector<ll> ans(N);
    int idx = 0;
    dfs(graph, C, ans, 0, -1, idx);
    rep(i, 0, N) {
        cout << ans[i] << " \n"[i + 1 == N];
    }
    return 0;
}