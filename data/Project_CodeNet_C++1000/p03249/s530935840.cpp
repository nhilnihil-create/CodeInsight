#include <bits/stdc++.h>
using namespace std;
const int MAXn = 1e5 + 10;
typedef pair<long long, int> pii;
pii ar[MAXn];
long long n, sz[MAXn], root, disroot, d[MAXn], hp3[MAXn];
vector<int> vec[MAXn];
vector<pii> ans;

bool cmp(pii p1, pii p2) {
	return p1.first > p2.first;
}

long long dfs1(int v, int  par) {
	long long res = 0;
	for (int i = 0; i < vec[v].size(); i++)
		if (vec[v][i] != par) {
			res += dfs1(vec[v][i], v) + hp3[vec[v][i]];
			hp3[v] += hp3[vec[v][i]];
		}
	hp3[v]++;

	return res;
	
}

void dfs2(int v, int par, long long sth) {
	if (sth != d[v]) {
		cout << -1;
		exit(0);
	}
	for (int i = 0; i < vec[v].size(); i++) {
		if (vec[v][i] != par) {
			dfs2(vec[v][i], v, sth - (hp3[vec[v][i]]) + (hp3[ar[0].second] - hp3[vec[v][i]]));
			
		}
		
	}
	
}
int main() {
	cin >> n;
	fill_n(sz, MAXn, 1);
	for (int i = 0; i < n; i++) {
		long long di;
		cin >> di;
		d[i] = di;
		ar[i].first = di;
		ar[i].second = i;
	}
	sort(ar, ar + n);
	for (int i = n - 1; i > 0; i--) {
		long long hp = ar[i].first - n;
		hp += 2LL * sz[ar[i].second];
		int hp2 = lower_bound(ar, ar + n, pii(hp, -1)) - ar;
		if (ar[hp2].first != hp)
			return cout << -1,0;
		sz[ar[hp2].second] += sz[ar[i].second];
		vec[ar[hp2].second].push_back(ar[i].second);
		vec[ar[i].second].push_back(ar[hp2].second);
		ans.push_back(pii(ar[i].second, ar[hp2].second));
	}
	disroot = dfs1(ar[0].second, -1);
	dfs2(ar[0].second, -1, disroot);
	if (ans.size() != n - 1)
		return cout << -1,0;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first + 1<< ' ' << ans[i].second + 1<< endl;
}