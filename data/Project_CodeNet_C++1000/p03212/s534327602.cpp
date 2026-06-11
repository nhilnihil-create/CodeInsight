#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> c;

bool is357(string x) {
	int exist3 = x.find('3');
	int exist5 = x.find('5');
	int exist7 = x.find('7');
	if (exist3 != -1 && exist5 != -1 && exist7 != -1) return true;
	else return false;
}

void get357Number(string s_prev) {

	if (s_prev.size() == 10) {
		return;
	}

	for (ll i = 0; i <= 2; i++) {

		if (i == 0) {
			string s_now = s_prev + '3';
			if (is357(s_now)) {
				c.emplace_back(stoll(s_now));
			}
			get357Number(s_now);
		}
		else if (i == 1) {
			string s_now = s_prev + '5';
			if (is357(s_now)) {
				c.emplace_back(stoll(s_now));
			}
			get357Number(s_now);
		}
		else { // i == 2
			string s_now = s_prev + '7';
			if (is357(s_now)) {
				c.emplace_back(stoll(s_now));
			}
			get357Number(s_now);
		}
	}
}


int main() {

	ll n; cin >> n;
	
	string s = "";

	get357Number(s);
	sort(c.begin(), c.end());

	ll ans;
	for (ll i = 0; i < c.size(); i++) {
		if (c[i] <= n) {
		}
		else {
			ans = i;
			break;
		}
	}

	cout << ans << endl;
	return 0;
}