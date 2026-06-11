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
	int N, K;
	cin >> N >> K;
	double res = 0;
	for (int i = 1; i <= N; i++) {
		int t = i;
		double a = 1;
		while (t < K) {
			t *= 2;
			a *= 0.5;
		}
		res += a;
	}
	res /= N;
	cout << fixed << setprecision(15) << res << endl;
}
