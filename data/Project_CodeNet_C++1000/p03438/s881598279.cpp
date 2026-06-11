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
#define int long long
	int n;
	cin >> n;
	int a[10010], b[10010];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum -= a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		sum += b[i];
	}
	bool ans = true;
	int o = 0, t = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			o += a[i] - b[i];
		}
		else {
			t += (b[i] - a[i] + 1) / 2;
		}
	}
	if (sum >= o && sum >= t) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
