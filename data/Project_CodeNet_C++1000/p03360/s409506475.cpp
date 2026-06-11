#include "bits/stdc++.h"
using namespace std;

int main() {
	int A, B, C, K;
	cin >> A >> B >> C >> K;
	int num = max(A, max(B, C));
	int ans = A + B + C - num;
	for (int i = 0; i < K; ++i) {
		num *= 2;
	}
	ans += num;
	cout << ans << endl;
}
