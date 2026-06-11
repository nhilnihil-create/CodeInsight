
// C - Unification

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string S;
	cin >> S;

	int r = 0;
	int b = 0;

	for (int i=0; i<S.size(); i++) {
		if (S[i] == '0') r++;
		else b++;
	}

	int ans = min(r, b) * 2;

	cout << ans << endl;

	return 0;
}