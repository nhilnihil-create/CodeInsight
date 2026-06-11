
// D - Xor Sum 2

// 尺取り法による解法

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll A[200000];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	ll ans = 0;

	int right = 0;
	ll sum = 0;
	ll xor_sum = 0;
	for (int left = 0; left < N; ++left) {
		while (right < N && ((sum + A[right]) == (xor_sum ^ A[right]))) {
			sum += A[right];
			xor_sum ^= A[right];
			right++;
		}

		ans += (right - left);

		if (right == left) ++right; // leftがrightを追い越さないようにする
		else {
			sum -= A[left];
			xor_sum ^= A[left];
		}
	}

	cout << ans << endl;

	return 0;
}