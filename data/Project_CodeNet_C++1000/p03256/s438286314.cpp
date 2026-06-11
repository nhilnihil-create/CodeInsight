#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <functional>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<vector<int>> g(n);
    vector<int> cntA(n), cntB(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        (s[b] == 'A' ? cntA[a] : cntB[a])++;
        (s[a] == 'A' ? cntA[b] : cntB[b])++;
    }
    vector<int> alive(n, true);
    int cnt = n;
    function<void(int)> del = [&](int u) {
        if (!alive[u]) return ;
        alive[u] = false, cnt--;
        for (int v: g[u]) {
            (s[u] == 'A' ? cntA[v] : cntB[v])--;
            if (alive[v] && (cntA[v] == 0 || cntB[v] == 0)) del(v);
        }
    };
    for (int i = 0; i < n; i++) if (cntA[i] == 0 || cntB[i] == 0) del(i);
    cout << (cnt ? "Yes" : "No") << endl;
    return 0;
}
