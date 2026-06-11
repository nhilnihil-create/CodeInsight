
// C - Coloring Colorfully

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string S;
	cin >> S;

	int cnt1 = 0;
	int cnt2 = 0;

	for (int i=0; i<S.size(); i++) {
		if (i % 2 == 0) {
			if (S[i] == '0') cnt1++;
			else cnt2++;
		} else {
			if (S[i] == '1') cnt1++;
			else cnt2++;
		}
	}

	int ans = min(cnt1, cnt2);

	cout << ans << endl;

	return 0;
}