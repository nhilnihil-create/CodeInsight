#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
	int n; cin >> n;
	vector<set<int>> to(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b;
		a--; b--;
		to[a].insert(b);
		to[b].insert(a);
	}
	vector<int> c(n);
	rep(i, n) cin >> c[i];
	sort(c.rbegin(), c.rend());
	queue<int> que;
	rep(i, n) {
		if (to[i].size() == 1) que.push(i);
	}
	ll sum = 0;
	for (int i = 1; i < n; ++i)sum += c[i];
	vector<int> ans(n);
	while (que.size()) {
		if (!c.size()) break;
		int v = que.front();
		que.pop();
		ans[v] = c.back();
		c.pop_back();
		int nv = *to[v].begin();
		to[nv].erase(v);
		if (to[nv].size() == 1) {
			que.push(nv);
		}
	}
	cout << sum << endl;
	rep(i, n)cout << ans[i] << (i == n - 1 ? "\n" : " ");
	return 0;
}