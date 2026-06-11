// AtCode.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdint.h>
#include <queue>
#include <bitset>

using namespace std;

#define MAX_N 200000

int dp[MAX_N+1];

int main() {

	int N;
	cin >> N;
	vector<long long> inputs;
	for (int i = 0; i < N; i++) {
		long long x;
		cin >> x;
		inputs.push_back(x);
	}


	fill(dp, dp + N + 1, 0);
	for (int i = 0; i < N; ++i) {
		// dp[j]:最後がjで終わる連続増加行列の長さ
		int j = inputs[i];
		dp[j] = dp[j - 1] + 1;
	}
	int maxnum = 0;
	for (int i = 0; i < N+1; ++i) {
		maxnum = max(maxnum, dp[i]);
	}

	cout << N - maxnum << endl;


	return 0;
}

