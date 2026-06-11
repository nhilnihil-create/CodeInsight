//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long

int N;
int A[200010];
int B[200010];
vector<int> x[30][2];
int cnt[30];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= 28; j++) {
			int mask = (2 << j) - 1;
			x[j][(A[i] >> j) & 1].push_back(mask & A[i]);
		}
	}
	for (int i = 0; i <= 28; i++) {
		for (int j = 0; j < 2; j++) {
			sort(x[i][j].begin(), x[i][j].end());
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	for (int i = 0; i < N; i++) {
		int BB = B[i];
		for (int j = 28; j >= 0; j--) {
			BB = BB & ((2 << j) - 1);
			if ((1 << j) <= BB) {
				int ub = x[j][1].size();
				int lb = (3 << j) - BB;
				lb = lower_bound(x[j][1].begin(), x[j][1].end(), lb) - x[j][1].begin();
				cnt[j] += (ub - lb) % 2;

				ub = (2 << j) - 1 - BB;
				ub = upper_bound(x[j][0].begin(), x[j][0].end(), ub) - x[j][0].begin();
				lb = 0;
				cnt[j] += (ub - lb) % 2;
			}
			else {
				int ub = (2 << j) - 1 - BB;
				ub = upper_bound(x[j][1].begin(), x[j][1].end(), ub) - x[j][1].begin();
				int lb = 0;
				cnt[j] += (ub - lb) % 2;

				ub = x[j][0].size();
				lb = (1 << j) - BB;
				lb = lower_bound(x[j][0].begin(), x[j][0].end(), lb) - x[j][0].begin();
				cnt[j] += (ub - lb) % 2;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 30; i++) {
		if (cnt[i] % 2) ans |= 1 << i;
	}
	cout << ans << endl;
	return 0;
}