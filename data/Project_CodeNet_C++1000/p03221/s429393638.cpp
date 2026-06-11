#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<set<pair<int, int>>> res(n);
	for (int i = 0; i < m; i++) {
		int p, x;
		cin >> p >> x;
		res[p - 1].insert({x, i});
	}
	vector<string> id(m);
	for (int i = 0; i < n; i++) {
		int k = 1;
		for (auto x : res[i]) {
			string pref = to_string(i + 1);
			pref = string(6 - pref.size(), '0') + pref;
			string suf = to_string(k);
			suf = string(6 - suf.size(), '0') + suf;
			id[x.second] = pref + suf;
			k++;
		}
	}
	for (int i = 0; i < m; i++) {
		cout << id[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
}