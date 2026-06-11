#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
int main() {
#ifdef local
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string s; cin >> s;
	int n = s.size();
	if(s[n - 1] != '0' || s[0] != '1') {
		cout << "-1\n";
		return 0;
	}
	for(int i = 0; i < n - 1; i++) {
		if(s[i] != s[n - 2 - i]) {
			return cout << "-1\n", 0;
		}
	}
	auto gen = [&](int n) {
		vector<pair<int, int> > edges;
		int now = 1, tail = 1;
		for(int i = 1; i < n; i++) {
			edges.emplace_back(tail, ++now);
			if(s[i - 1] == '1') tail = now;
		}
		return edges;
	};
	auto ans = gen(n);
	for(auto &e : ans) {
		cout << e.fi << ' ' << e.se << '\n';
	}
	return 0;
}
