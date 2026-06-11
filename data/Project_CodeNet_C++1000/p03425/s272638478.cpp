	#include <bits/stdc++.h>
	using namespace std;
	typedef long long ll;
	string s = "MARCH";
	map<char, ll> cnt;
	ll res = 0;
	void find(int p = 0, int l = 0, string prefix = "") {
		if (p == 3) {
			res += cnt[prefix[0]] * cnt[prefix[1]] * cnt[prefix[2]];
			return;
		}
		for (int i = l; i < s.size(); i++) {
			find(p + 1, i + 1, prefix + s[i]);
		}
	}

	void solve() {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string t;
			cin >> t;
			cnt[t[0]]++;
		}
		find();
		cout << res;
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