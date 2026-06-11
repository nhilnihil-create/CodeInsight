
// C - Minimization

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int A[100000];

int main() {
	int N, K;
	cin >> N >> K;

	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	int ans;
	if (N <= K) ans = 1;
	else ans = (N-2) / (K-1) + 1;

	cout << ans << endl;

	return 0;
}