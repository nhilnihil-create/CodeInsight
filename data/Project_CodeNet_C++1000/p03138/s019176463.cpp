#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int main() {
	bitset<45> b[100010];
	int n;
	long long k;
	cin >> n >> k;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		ans += a;
		b[i] = (a);
	}
	long long t = 1;
	long long sum[100] = { 0 };
	for (int i = 0; i <= 40; i++) {
		for (int j = 0; j < n; j++) {
			if (b[j][i]) {
				sum[i] -= t;
			}
			else {
				sum[i] += t;
			}
		}
		t *= 2;
	}
	for (int i = 0; i <= 40; i++) {
		if (sum[i] < 0) {
			sum[i] = 0;
		}
	}
	t /= 2;
	long long co = 0, co1 = 0;
	long long ma = 0;
	for (int i = 40; i >= 0; i--) {
		if (t <= k) {
			if (sum[i] > ma) {
				ma = sum[i];
			}
		}
		if (co + t <= k) {
			co += t;
			if (co1 + sum[i] > ma) {
				ma = co1 + sum[i];
			}
			long long co2 = 0;
			for (int j = i - 1; j >= 0; j--) {
				co2 += sum[j];
			}
			if (co1 + co2 > ma) {
				ma = co1 + co2;
			}
			co1 += sum[i];
		}
		t /= 2;
	}
	cout << ans + ma << endl;
	return 0;
}
