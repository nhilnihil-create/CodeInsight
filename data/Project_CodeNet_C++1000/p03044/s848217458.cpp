#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
template <class T>
using Grid = vector<vector<T>>;
vector<vector<pair<int, int>>> g;
vector<int> ans;
void dfs(int i) {
    for (auto x : g[i]) {
        if (ans[x.first] != -1)
            continue;
        if (x.second % 2 == 0)
            ans[x.first] = ans[i];
        else
            ans[x.first] = !ans[i];
        dfs(x.first);
    }
}
int main() {
    int N;
    cin >> N;
    g.resize(N + 1);
    rep(i, N - 1) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    ans.assign(N + 1, -1);
    ans[1] = 0;
    dfs(1);
    rep2(i, N) printf("%d\n", ans[i]);
}