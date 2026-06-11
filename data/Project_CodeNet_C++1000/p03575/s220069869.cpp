#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = 1001002003004005006ll;
const int inf = 1001001001;
const int mod = 1000000007;

vector<int> g[55];
int vi[55];
map<P, bool> mp;

void dfs(int s) {
	vi[s] = 1;
	for (auto& c : g[s]) {
		if (vi[c] >= 1 || mp[P(s, c)]) continue;
		dfs(c);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<P> res;
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
		res.emplace_back(a, b);
	}
	int ans = 0;
	rep(i, m) {
		int a = res[i].first;
		int b = res[i].second;
		mp[P(a, b)] = true;
		mp[P(b, a)] = true; 
		memset(vi, -1, sizeof(vi));
		dfs(0);
		bool ng = false;
		rep(i, n) if (vi[i] == -1) ng = true;
		if (ng) ans++;
		mp[P(a, b)] = false;
		mp[P(b, a)] = false;
	}
	cout << ans << endl;
	return 0;
}