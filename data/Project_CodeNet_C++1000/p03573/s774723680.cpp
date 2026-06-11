
// A - One out of Three

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	int ans;
	if (A == B) {
		ans = C;
	} else {
		if (B == C) {
			ans = A;
		} else {
			ans = B;
		}
	}

	cout << ans << endl;

	return 0;
}