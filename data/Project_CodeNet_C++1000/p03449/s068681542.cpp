
// C - Candies

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int A[2][100];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> A[0][i];
	}

	for (int i=0; i<N; i++) {
		cin >> A[1][i];
	}

	int ans = 0;

	for (int i=0; i<N; i++) {
		int candies = 0;

		for (int j=0; j<=i; j++) {
			candies += A[0][j];
		}

		for (int j=i; j<N; j++) {
			candies += A[1][j];
		}

		ans = max(ans, candies);
	}

	cout << ans << endl;

	return 0;
}