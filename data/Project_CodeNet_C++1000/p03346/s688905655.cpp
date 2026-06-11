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
int a[200020];
int sum[200020] = { 0 };
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum[a[i]]++;
		sum[a[i]] += sum[a[i] - 1];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < sum[i]) {
			ans = sum[i];
		}
	}
	cout << n - ans << endl;
	return 0;
}
