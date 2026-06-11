#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, int> pli;

const int N = 1e5 + 10;
int n, cnt[N], par[N], mark[N];
ll sum[N];
pli ar[N];
unordered_map <ll, int> mp;
vector <int> ch[N];

void dfs(int v) {
	mark[v] = 1;
	for (int i : ch[v]) {
		dfs(i);
		sum[v] += sum[i] + cnt[i];
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(cnt, cnt + N, 1);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i].first;
		ar[i].second = i;
		mp[ar[i].first] = i;
	}
	sort(ar, ar + n);
	
	for (int i = n - 1; i > 0; i--) {
		int v = ar[i].second;
		ll nd = ar[i].first - n + (ll)2 * cnt[v];
		if (mp.find(nd) == mp.end() || 2 * cnt[v] > n)
			return cout << -1, 0;
		
		int p = mp[nd];
		ch[p].push_back(v);
		par[v] = p;
		cnt[p] += cnt[v];
	}
	
	dfs(ar[0].second);
	if (sum[ar[0].second] != ar[0].first)
		return cout << -1, 0;
	
	for (int i = 0; i < n; i++)
		if (!mark[i])
			return cout << -1, 0;
	
	for (int i = 0; i < n; i++)
		if (i != ar[0].second)
			cout << i + 1 << " " << par[i] + 1 << '\n';
}