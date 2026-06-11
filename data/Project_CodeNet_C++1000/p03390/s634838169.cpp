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
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
	}
	int C;
	int k;
	set<int> X;
	set<int> Y;
	int t = 0;
	for (int i = 0; i < N; i++) {
		C = A[i] * B[i];
		k = sqrt(A[i] * B[i]);
		if (k*k >= A[i] * B[i]) {
			k--;
		}
		t++;
		if (k*(k + 1) < C) {
			res = 2 * k;
			if (A[i] == k + 1) {
				if (k*(k + 2) >= C) {
					res--;
				}
			}
			if (B[i] == k + 1) {
				if (k*(k + 2) >= C) {
					res--;
				}
			}
			if (A[i] <= k)res--;
			if (B[i] <= k)res--;
		}
		else {
			res = 2 * k - 1;
			if (A[i] <= k)res--;
			if (B[i] <= k)res--;
		}
		cout << res << endl;
	}

}