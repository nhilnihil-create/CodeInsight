#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	if (n == 0 || n == 1) {
		cout << n << endl;
		return 0;
	}
	vector<int>ans;
	ll x = 1;
	while (n != 0) {
		ll n0 = n;
		ll n1 = n + x;
		if (n0 % (-2 * x) == 0)ans.push_back(0);
		else {
			ans.push_back(1);
			n -= x;
		}
		x *= (-2);
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)cout << ans.at(i);
}