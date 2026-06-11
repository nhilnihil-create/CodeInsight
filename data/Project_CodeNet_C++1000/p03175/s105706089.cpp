#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const ll MOD = 1e9 + 7;

ll mod(ll a, ll b) {
	if (a >= MOD) a = a % MOD;
	if (b >= MOD) b = b % MOD;
	return (a * b) % MOD;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
	int n;
	cin >> n;
	vector<ll> white(n + 1, 1), black(n + 1, 1), leaf(n + 1), vis(n + 1);
	vector<vector<int> > edge(n + 1);
	for (int i = 1, x, y; i < n; i++) {
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
		leaf[x]++;
		leaf[y]++;
	}
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (leaf[i] == 1) 	q.push(i);
	}
	int y;
	while (!q.empty()) {
		y = q.front();
		q.pop();
		vis[y] = 1;
		for (int i = 0; i < (int)edge[y].size(); i++) {
			int x = edge[y][i];
			if (vis[x] == 0) {
				white[x] = mod(white[x], white[y] + black[y]);
				black[x] = mod(black[x], white[y]);
				leaf[x]--;
			}
			if (leaf[x] == 1  && vis[x] == 0) q.push(x);
		}
	}

	ll ans = (white[y] + black[y]) % MOD;
	cout << ans << '\n';

	return 0;
}
