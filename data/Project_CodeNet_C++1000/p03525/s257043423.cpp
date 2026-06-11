#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 998244353
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N; cin >> N;
	vector<int> D(N);
	vector<int> cnt(13);
	for (int i = 0; i < N; i++){
		cin >> D[i];
		cnt[D[i]]++;
	}
	bool z = true;
	for (int i = 0; i <= 12; i++) {
		if (cnt[i] >= 3 || cnt[0] >= 1) z = false;
	}
	if (!z) cout << 0 << endl;
	else {
		int ans = -1;
		if (N >= 24) cout << 0 << endl;
		else if (N == 23) {
			cout << 1 << endl;
		}
		else {
			int mx = pow(2, N);
			for (int i = 0; i < mx; i++) {
				vector<int> bit(N);
				int temp = i;
				for (int j = 0; temp; j++) {
					bit[j] = temp % 2;
					temp /= 2;
				}
				vector<int> time(N);
				for (int j = 0; j < N; j++) {
					if (bit[j])time[j] = 24 - D[j];
					else time[j] = D[j];
				}
				sort(time.begin(), time.end());
				int di = time[0];
				for (int k = 1; k < N; k++) {
					di = min(di, time[k] - time[k - 1]);
				}
				di = min(di, 24 - time[N - 1]);
				ans = max(ans, di);
			}
			cout << ans << endl;
		}
	}
}