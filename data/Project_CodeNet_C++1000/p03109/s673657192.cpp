#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	string ans = "Heisei";
	if (5 <= (s[6] - '0') || (s[5] - '0') == 1) {
		ans = "TBD";
	}
	cout << ans << endl;
	return 0;
}