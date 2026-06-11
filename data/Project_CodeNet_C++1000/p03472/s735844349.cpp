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
using namespace std;
long long a[100010], b[100010];
int main() {
	int n;
	long long h;
	cin >> n >> h;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	long long s = a[n - 1];
	int co = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s > b[i]) {
			break;
		}
		h -= b[i];
		co++;
		if (h <= 0) {
			cout << co << endl;
			return 0;
		}
	}
	cout << co + (h + s - 1) / s << endl;
	return 0;
}
