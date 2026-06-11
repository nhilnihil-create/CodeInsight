
// C - Traveling

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	string ans = "Yes";

	int t, x, y;
	int prev_t = 0, prev_x = 0, prev_y = 0;
	for (int i=0; i<N; i++) {
		cin >> t >> x >> y;
		if (t - prev_t < abs(x - prev_x) + abs(y - prev_y)) ans = "No";
		if (((t - prev_t) - (abs(x - prev_x) + abs(y - prev_y))) % 2 != 0) ans = "No";
		prev_t = t;
		prev_x = x;
		prev_y = y;
	}

	cout << ans << endl;

	return 0;
}