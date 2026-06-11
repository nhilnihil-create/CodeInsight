
// C - Linear Approximation

// 中央値を求める解法

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int N;
ll B[200001];

ll err(int k) {
	ll result = 0;

	for (int i=1; i<=N; i++) {
		result += abs(B[i] - k);
	}

	return result;
}

int main() {
	cin >> N;

	for (int i=1; i<=N; i++) {
		int A;
		cin >> A;
		B[i] = A - i;
	}

	sort(B+1, B+N+1);

	ll ans = err(B[N/2 + 1]);

	cout << ans << endl;

	return 0;
}