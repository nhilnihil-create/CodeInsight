
// A - Rotation

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string C1, C2;
	cin >> C1 >> C2;

	string ans = "YES";

	for (int i=0; i<3; i++) {
		if (C1[i] != C2[2-i]) ans = "NO";
	}

	cout << ans << endl;

	return 0;
}