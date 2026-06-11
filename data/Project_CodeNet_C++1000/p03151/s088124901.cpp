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
int a[100010], b[100010];
int main() {
#define int long long
	priority_queue<int> que;
	int sum = 0, sum1 = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		sum1 += b[i];
		que.push(a[i] - b[i]);
		a[i] = a[i] - b[i];
	}
	if (sum < sum1) {
		cout << "-1" << endl;
		return 0;
	}
	sort(a, a + n);
	int co = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (co <= 0) {
			co += que.top();
			que.pop();
			ans++;
		}
		if (a[i] < 0) {
			co += a[i];
			ans++;
		}
	}
	if (ans == 1) {
		ans = 0;
	}
	cout << ans << endl;
	return 0;
}
