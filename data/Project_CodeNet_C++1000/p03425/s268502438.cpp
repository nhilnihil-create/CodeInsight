#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n; cin >> n;
	const int p = 5;
	vector<ll> num(p, 0);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if (s[0] == 'M') num[0]++;
		if (s[0] == 'A') num[1]++;
		if (s[0] == 'R') num[2]++;
		if (s[0] == 'C') num[3]++;
		if (s[0] == 'H') num[4]++;
	}
	ll ans = 0;
	ans += num[0] * num[1] * num[2];
	ans += num[0] * num[1] * num[3];
	ans += num[0] * num[1] * num[4];

	ans += num[0] * num[2] * num[3];
	ans += num[0] * num[2] * num[4];

	ans += num[0] * num[3] * num[4];

	ans += num[1] * num[2] * num[3];
	ans += num[1] * num[2] * num[4];
	ans += num[1] * num[3] * num[4];

	ans += num[2] * num[3] * num[4];
	cout << ans << endl;
    return 0;
}