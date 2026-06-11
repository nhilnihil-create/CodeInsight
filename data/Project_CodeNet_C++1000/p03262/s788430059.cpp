
// C - Skip

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int x[100001];

int main() {
	int N, X;
	cin >> N >> X;

	x[0] = X;
	int min_x = X;
	for (int i=1; i<=N; i++) {
		cin >> x[i];
		min_x = min(min_x, x[i]);
	}

	for (int i=0; i<=N; i++) {
		x[i] -= min_x;
	}

	int ans = x[0];
	for (int i=0; i<=N; i++) {
		ans = __gcd(ans, x[i]);
	}

	cout << ans << endl;

	return 0;
}