#include <iostream>
typedef long long ll;
using namespace std;

int main() {
	string s; cin >> s;
	ll k; scanf("%lld", &k);

	ll ans;
	if (s[0] != '1') ans = s[0] - '0';
	else {
		int cnt = 0;
		while (s[0] == '1') {
			s = s.substr(1, s.size() - 1);
			++cnt;
		}

		if (cnt >= k) ans = 1;
		else ans = s[0] - '0';
	}

	printf("%lld", ans);
	return 0;
}