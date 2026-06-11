#include "bits/stdc++.h"
using namespace std;

int main() {
	int H, W, D;
	cin >> H >> W >> D;
	vector<pair<int, int>>data(H*W);
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			int num;
			cin >> num;
			data[num] = make_pair(i, j);
		}
	}
	//前処理、累積和
	vector<int>sum(H*W + 1);
	for (int i = 1; i <= H * W; ++i) {
		if (i <= D) {
			sum[i] = 0;
		}
		else {
			int j = i - D;
			sum[i] = sum[i - D] + abs(data[j].first - data[i].first) + abs(data[j].second - data[i].second);
		}
	}

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int L, R;
		cin >> L >> R;
		cout << sum[R] - sum[L] << endl;
	}
	return 0;
}
