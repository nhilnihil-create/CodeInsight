
// B - Addition and Multiplication

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N, K;
	cin >> N >> K;

	int ans = 1;

	for (int i=0; i<N; i++) {
		if (ans * 2 < ans + K) ans *= 2;
		else ans += K;
	}

	cout << ans << endl;

	return 0;
}