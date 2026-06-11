
// D - Partition

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N, M;
	cin >> N >> M;

	if (N == 1) {
		cout << M << endl;
		return 0;
	}

	int ans = 1;

	for (int i=1; i*i<=M; i++) {
		if (M % i == 0) {
			int j = M / i;
			 if (M / i >= N) ans = max(ans, i);
			 if (M / j >= N) ans = max(ans, j);
		}
	}

	cout << ans << endl;

	return 0;
}