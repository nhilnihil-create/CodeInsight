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
	long long a, b;
	cin >> a >> b;
  long long z=0;
	a = max(z, a - 1);
	long long ans, ans1;
	if (a % 4 == 0) {
		ans = a;
	}
	if (a % 4 == 1) {
		ans = 1;
	}
	if (a % 4 == 2) {
		ans = a + 1;
	}
	if (a % 4 == 3) {
		ans = 0;
	}
	if (b % 4 == 0) {
		ans1 = b;
	}
	if (b % 4 == 1) {
		ans1 = 1;
	}
	if (b % 4 == 2) {
		ans1 = b + 1;
	}
	if (b % 4 == 3) {
		ans1 = 0;
	}
	ans = ans ^ ans1;
	cout << ans << endl;
	return 0;
}
