
// C - Base -2 Number

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	ll N;
	cin >> N;

	string ans = "";

	if (N == 0) {
		cout << 0 << endl;
		return 0;
	}

	while(N != 0) {
		int r = N % (-2);

		if (r == 1 || r == -1) ans = '1' + ans;
		else ans = '0' + ans;

		if (r != 0) N--;
		N /= (-2);
	}

	cout << ans << endl;

	return 0;
}