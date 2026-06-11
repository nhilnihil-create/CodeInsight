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
long long a[100010];
int main() {
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	long long l = 2, r = 2;
	for (int i = k - 1; i >= 0; i--) {
		long long kl = ((l + a[i] - 1) / a[i]) * a[i];
		long long kr = (r / a[i]) * a[i];
		kr += a[i] - 1;
		if (kl > r || kr < l) {
			cout << "-1" << endl;
			return 0;
		}
		else {
			l = kl;
			r = kr;
		}
	}
	cout << l << " " << r << endl;
}
