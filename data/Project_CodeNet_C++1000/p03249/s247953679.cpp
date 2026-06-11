#include "bits/stdc++.h"
using namespace std;
long long d[100010];
#define endl '\n'
typedef pair <long long, int> pii;

int sub[100010];
int par[100010];

int dis[100010];
vector <int> g[100010]; 

void dfs(int x, int par) {
	for(auto i : g[x]) {
		if(i - par) {
			dis[i] = 1 + dis[x];
			dfs(i, x);
		}
	}
}


int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio (false);
	cin.tie(0);

	int n;
	cin >> n;

	map <long long, int> mp;
	vector <pii> v;
	for(int i = 1; i <= n; i++) {
		cin >> d[i];
		v.emplace_back(d[i], i);
		mp[d[i]] = i;
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	for(int i = 1; i <= n; i++) {
		sub[i] = 1;
		par[i] = i;
	}
	for(int i = 0; i < n-1; i++) {
		int node = v[i].second;
		int diff = n - 2 * sub[node];
		long long par_d = v[i].first - diff;
		if(diff == 0 || mp.find(par_d) == mp.end()) {
			cout << -1 << endl;
			exit(0);
		}
		par[node] = mp[par_d];
		sub[par[node]] += sub[node];
		g[par[node]].push_back(node);
		g[node].push_back(par[node]);
	}
	memset(dis, -1, sizeof dis);
	dis[1] = 0;
	dfs(1, 0);

	long long tot = 0;
	for(int i = 1; i <= n; i++) {
		if(dis[i] == -1) {
			cout << -1 << endl;
			exit(0);
		}
		tot += dis[i];
	}
	if(tot != d[1]) {
		cout << -1 << endl;
		exit(0);
	}
	for(int i = 0; i < n-1; i++) {
		int node = v[i].second;
		cout << node << " " << par[node] << endl;
	}
	return 0;
}