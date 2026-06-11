#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> c;
void dfs(string s) {
	if (s.size() == 11) {		
		return;
	}
	if (3 <= s.size() && s.size() <= 10) {
		bool isExist3 = false;
		bool isExist5 = false;
		bool isExist7 = false;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '3') isExist3 = true;
			if (s[i] == '5') isExist5 = true;
			if (s[i] == '7') isExist7 = true;
		}
		if(isExist3 && isExist5 && isExist7) c.push_back(stoll(s));
	}
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			s += '3';
			dfs(s);
			s.pop_back();
		}
		else if (i == 1) {
			s += '5';
			dfs(s);
			s.pop_back();
		}
		else if (i == 2) {
			s += '7';
			dfs(s);
			s.pop_back();
		}
	}
}

int main() {

	ll n; cin >> n;
	string s = "";
	dfs(s);
	sort(c.begin(), c.end());
	ll ans = 0;
	for (ll i = 0; i <= c.size(); i++) {
		if (c[i] <= n) ans++;
		else break;
	}
	cout << ans << endl;
	return 0;
}