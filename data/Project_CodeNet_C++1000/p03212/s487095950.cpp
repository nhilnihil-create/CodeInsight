#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> c;

bool getFlag357Number(string x) {
	bool exist3 = false;
	bool exist5 = false;
	bool exist7 = false;
	for (ll i = 0; i < x.size(); i++) {
		if (x[i] == '3') exist3 = true;
		else if (x[i] == '5') exist5 = true;
		else if (x[i] == '7') exist7 = true;		
	}
	bool res;
	if (exist3 && exist5 && exist7) return true;
	else return false;
}

void get357Number(string s_prev) {

	if (s_prev.size() == 10) {
		return;
	}

	for (ll i = 0; i <= 2; i++) {

		if (i == 0) {
			string s_now = s_prev + '3';
			if (getFlag357Number(s_now)) {
				c.emplace_back(stoll(s_now));
			}
			get357Number(s_now);
		}
		else if (i == 1) {
			string s_now = s_prev + '5';
			if (getFlag357Number(s_now)) {
				c.emplace_back(stoll(s_now));
			}
			get357Number(s_now);
		}
		else { // i == 2
			string s_now = s_prev + '7';
			if (getFlag357Number(s_now)) {
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