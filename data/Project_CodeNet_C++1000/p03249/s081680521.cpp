#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const int N = 1e5 + 100;

ll n, d[N], cnt[N], dp[N];
vector<int> nei[N];
vector<pll> vec, ans;
bool no_homo;
unordered_map<ll, int> v_d;

void dfs(int v, int par = -1) {
	for (int u: nei[v])
		if(u != par) {
			dfs(u, v);
			dp[v] += dp[u] + cnt[u];
		}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> d[i], vec.push_back(pll(d[i], i)), cnt[i] = 1, v_d[d[i]] = i;
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	for (int i = 0; i < n - 1; i++) {
		ll v = vec[i].second, want = vec[i].first + 2 * cnt[v] - n, u = v_d[want];
		if(2 * cnt[v] > n)
			no_homo = true;
		//cerr << v << " want -> " << u << ' ' << want << '\n';
		if(u == 0)
			no_homo = true;
		else {
			cnt[u] += cnt[v];
			ans.push_back(pll(v, u));
			nei[v].push_back(u);
			nei[u].push_back(v);
		}
	}
	dfs(vec.back().second);
	if(d[vec.back().second] != dp[vec.back().second])
		no_homo = true;
	if(no_homo) {
		cout << -1;
		return 0;
	}
	for (pll p: ans)
		cout << p.first << ' ' << p.second << '\n';
	return 0;
}// 1 BASE