#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    const int inf = 1e6;
    vector<int> d(n, inf);
    auto dfs = [&](int v) {
        stack<int> q;
        q.push(v);
        d[v] = 1;
        while (!q.empty()) {
            int v = q.top();
            q.pop();
            for (int w : g[v]) {
                if (d[w] == inf) {
                    d[w] = d[v] + 1;
                    q.push(w);
                }
            }
        }
    };
    dfs(0);
    int v = distance(d.begin(), max_element(d.begin(), d.end()));
    fill(d.begin(), d.end(), inf);
    dfs(v);
    int D = *max_element(d.begin(), d.end());
    vector<int> W{0, 1, 0};
    W.reserve(D + 1);
    for (int dd = 3; dd <= D; ++dd) {
        W.push_back(!(W[dd - 1] & W[dd - 2]));
    }
    cout << (W[D] ? "First" : "Second") << endl;
    return 0;
}
