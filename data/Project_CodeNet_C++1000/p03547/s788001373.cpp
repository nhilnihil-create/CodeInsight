
// A - HEX

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	char X, Y;
	cin >> X >> Y;

	string ans;
	if (X < Y) ans = "<";
	else if (X > Y) ans = ">";
	else ans = "=";

	cout << ans << endl;

	return 0;
}