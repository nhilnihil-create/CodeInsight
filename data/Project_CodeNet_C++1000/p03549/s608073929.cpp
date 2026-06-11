
// C - HSI

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N, M;
	cin >> N >> M;

	int E = pow(2, M);

	int ans = (N - M) * 100 * E + M * 1900 * E;

	cout << ans << endl;

	return 0;
}