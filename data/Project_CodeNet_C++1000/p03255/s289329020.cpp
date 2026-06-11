#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, X;
	cin >> N >> X;
	vector<int> A(N);
	int res = -1;
	vector<int> sum(N + 1);
	sum[0] = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum[i + 1] = sum[i] + A[i];
	}
	int k = 0;

	for (int i = 0; i < N; i++) {
		k += A[i] * 5;
	}
	for (int i = (N + 1) / 2; i >= 1; i--) {
		k = 0;
		for (int j = 0; j < N; j += i) {
			k += (sum[N - j] - sum[max((int)0, N - (j + i))]) * max((int)5, (2 * (j/i) + 3));
			//cerr << i << " " << N - j << " " << max((int)0, N - (j + i)) <<" " << max((int)5, (2 * j + 3)) << endl;
		}
		int ans = k + X*i + N*X;
		//cerr << i << " " << ans << endl;
		if (res == -1 || res > ans) {
			res = ans;
		}
		else {
			break;
		}


	}

	cout << res << endl;
}