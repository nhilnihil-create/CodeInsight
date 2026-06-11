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
	double n;
	double a[100];
	double co = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		co += a[i];
	}
	co /= n;
	double min = 1000000007;
	int ans;
	for (int j = 0; j < n; j++) {
		if (abs(co - a[j]) < min) {
			min = abs(co - a[j]);
			ans = j;
		}
	}
	cout << ans << endl;
}