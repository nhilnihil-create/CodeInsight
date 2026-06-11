#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
 
int n, m;
string dis(int g) {
	string t = to_string(g);
	while (t.size()<6) t = '0' + t;
	return t;
}

int main() {
	cin >> n >> m;
	vector<vector<P>> a(n);
	vector<string> ans(m);
	int p, y;
	rep(i,m) {
		cin >> p >> y;
		a[p-1].push_back({y, i});
	}

	int idx;
	rep(i,n) {
		if (a[i].empty()) continue; 
		sort(a[i].begin(), a[i].end());
		for (int j = 0; j < a[i].size(); j++)
		{
			idx = a[i][j].second;
			ans[idx] = dis(i+1) + dis(j+1);
		}
		
	}
	rep(i,m) {
		cout << ans[i] << endl;
	} 
	return 0;
}