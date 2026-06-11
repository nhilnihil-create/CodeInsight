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
	int N, A, B;
	cin >> N >> A >> B;
	if (A + B > N + 1) {
		cout << -1 << endl;
		return 0;
	}
	//cerr << "ok" << endl;
	vector<int> res(N+B, -1);
	vector<int> res2(N+B, -1);
	bool ok = true;
	int st = B;
	int cur = 0;
	int rem = N;
	int k = 0;
	while (true) {
		if (rem + cur == A) {
			break;
		}
		if (rem == 0) {
			ok = false;
			break;
		}
		//cerr << st << " " << k << endl;
		res[st - 1] = k;
		if (st%B == 0) {
			cur++;
		}
		st--;
		rem--;
		k++;
		if (st%B == 0) {
			st += 2 * B;
		}
		
	}
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	int t = 0;
	for (int i = 0; i < res.size(); i++) {
		if (res[i] != -1) {
			res2[t] = res[i];
			t++;
		}
	}
	swap(res, res2);
	for (int i = k; i < N; i++) {
		res[i] = i;
	}
	for (int i = 0; i < N; i++) {
		if (i > 0)cout << " ";
		cout << res[i] + 1;
	}
	cout << endl;
}