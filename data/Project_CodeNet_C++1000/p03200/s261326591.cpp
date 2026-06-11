
// A - Irreversible operation

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string S;
	cin >> S;

	if (S.size() == 1) {
		cout << 0 << endl;
		return 0;
	}

	ll ans = 0;
	ll cnt = 0;
	for (int i=0; i<S.size(); i++) {
		if (S[i] == 'B') cnt++;
		else ans += cnt;
	}

	cout << ans << endl;

	return 0;
}