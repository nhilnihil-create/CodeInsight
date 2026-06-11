#include <iostream>
#include <string>
#include <algorithm>
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
int sum[300030] = { 0 }, sum1[300030] = { 0 };
int main() {
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') {
			sum[i + 1]++;
		}
		sum[i + 1] += sum[i];
	}
	sum[n + 1] += sum[n];
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == 'E') {
			sum1[i + 1]++;
		}
		sum1[i + 1] += sum1[i + 2];
	}
	sum1[0] += sum1[1];
	int ans = 1000000007;
	for (int i = 1; i <= n; i++) {
		if (ans > sum[i - 1] + sum1[i + 1]) {
			ans = sum[i - 1] + sum1[i + 1];
		}
	}
	cout << ans << endl;
	return 0;
}