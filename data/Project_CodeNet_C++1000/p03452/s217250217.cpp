#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
//printf("%.10f\n", n);
ll ok[12345678], cost[12345678];
signed main() {
    ll n, m, l, r, d, z = 0, ans = 0;
	cin >> n >> m; map <ll, map<ll, ll>> ma;
	vector<vector<ll>> G(123456);
    queue<ll> que;
    if (m == 0) { cout << "Yes" << endl; return 0; }
    for (int h = 0; h <= n + 10; h++) { ok[h] = 1; }
	for (int h = 0; h < m; h++) {
		cin >> l >> r >> d; ma[l][r] = d;
        G[l].push_back(r); ok[r] = 0;
	}
    for (int i = 0; i <= n; i++) {
        if (ok[i] != 0) {
            if (!G[i].empty()) { cost[i] = 1; que.push(i); }
        }
    }
    if (que.empty()) { cout << "No" << endl; return 0; }
    while (que.size()) {
        for (int i = 0; i < G[que.front()].size(); i++) {
            if (cost[G[que.front()][i]] == 0) {
                que.push(G[que.front()][i]);
                cost[G[que.front()][i]] = cost[que.front()] + ma[que.front()][G[que.front()][i]];
            }
            else {
                if (cost[G[que.front()][i]] != cost[que.front()] + ma[que.front()][G[que.front()][i]]) {
                    cout << "No" << endl; return 0;
                }
            }
        }
        que.pop();
    }
    cout << "Yes" << endl;
    return 0;
}