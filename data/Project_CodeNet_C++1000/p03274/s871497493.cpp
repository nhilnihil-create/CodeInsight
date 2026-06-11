#include <bits/stdc++.h>
using namespace std;

int main() {
	// cin.tie(0);
	// ios::sync_with_stdio(false);

	int N, K;
	scanf("%d %d", &N, &K);

	vector<int> x(N);
	int x_tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &x_tmp);
		x[i] = x_tmp;
	}

	int result = 300000000;
	for (int i = 0; i + K - 1 < N; i++) {
		result = min(result, min(abs(x[i]), abs(x[i + K - 1])) +
		                         abs(x[i + K - 1] - x[i]));
	}
	cout << result;

	// vector<int> x_pos;
	// vector<int> x_neg;
	// int x_tmp, i_pos = 0, i_neg = 0;
	// int num_0 = 0;
	// for (int i = 0; i < N; i++) {
	// 	scanf("%d", x_tmp);
	// 	if (x_tmp > 0) {
	// 		x_pos[i_pos] = x_tmp;
	// 	} else if (x_tmp < 0) {
	// 		x_neg[i_neg] = -x_tmp;
	// 	} else {
	// 		num_0++;
	// 	}
	// }

	// sort(x_pos.rbegin(), x_pos.rend());
	// sort(x_neg.rbegin(), x_neg.rend());
	// int result = ;
	// for (int i = max(0, K - 1 - x_neg.size());
	//      i < x_pos.size() && K - i - 2 < x_neg.size(); i++) {
	// 	if (x_pos[i] > x_neg[N - i - 1]) {
	// 		result = min(result, x_pos[i] + x_neg[K - i - 2] * 2);
	// 	} else {
	// 		result = min(result, x_pos[i] * 2 + x_neg[K - i - 2]);
	// 	}
	// }

	return 0;
}