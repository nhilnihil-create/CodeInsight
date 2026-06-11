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
int sum[200020] = { 0 }, sum1[200020] = { 0 };
int main() {
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '.') {
			sum[i]++;
		}
		else if (s[i] == '#') {
			sum1[i]++;
		}
		if (i != 0) {
			sum[i] += sum[i - 1];
			sum1[i] += sum1[i - 1];
		}
	}
	int ans = 1000000007;
	for (int i = 0; i < n; i++) {
		int ans1 = sum1[i] + sum[n - 1] - sum[i];
		if (ans1 < ans) {
			ans = ans1;
		}
	}
	if (sum[n - 1] < ans) {
		ans = sum[n - 1];
	}
	if (sum1[n - 1] < ans) {
		ans = sum1[n - 1];
	}
	cout << ans << endl;

}