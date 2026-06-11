#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	ll ans = 0;
	ll b_a = 0;
	ll b_x = 0;
	ll x_a = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length()-1; j++) {
			if (s.at(j) == 'A' && s.at(j + 1) == 'B')ans++;
		}
		if (s.at(0) == 'B' && s.at(s.length() - 1) == 'A')b_a++;
		else if (s.at(0) == 'B')b_x++;
		else if (s.at(s.length() - 1) == 'A')x_a++;
	}
	ll x = 1;
	if (x_a == 0) {
		if (b_a == 0)ans += 0;
		else {
			if (b_x == 0)ans += b_a - 1;
			else ans += b_a;
		}
	}
	else ans += b_a + min(x_a, b_x);
	cout << ans << endl;

}