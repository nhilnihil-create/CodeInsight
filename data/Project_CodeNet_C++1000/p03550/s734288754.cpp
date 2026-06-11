
// D - ABS

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int N;
int a[2000];

int X_max(int k, int Z, int W);
int Y_min(int k, int Z, int W);

// 手番がXでk以降が残っている時のスコアの最大値
int X_max(int k, int Z, int W) {
	if (k == N) {
		return (abs(Z - W));
	}

	int result = 0;
	for (int i=k; i<N; i++) {
		result = max(result, Y_min(i+1, a[i], W));
	}

	return result;
}

// 手番がYでk以降が残っている時のスコアの最小値
int Y_min(int k, int Z, int W) {
	if (k == N) {
		return (abs(Z - W));
	}

	int result = INF;
	for (int i=k; i<N; i++) {
		result = min(result, X_max(i+1, Z, a[i]));
	}

	return result;
}


int main() {
	int Z, W;
	cin >> N >> Z >> W;

	for (int i=0; i<N; i++) {
		cin >> a[i];
	}

	int ans = X_max(max(0, N-2), Z, W);

	cout << ans << endl;

	return 0;
}