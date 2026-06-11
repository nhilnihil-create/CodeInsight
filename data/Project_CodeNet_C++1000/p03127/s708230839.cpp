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
long long gcd(long long a, long long b) {
	if (a % b == 0) {
		return (b);
	}
	else {
		return (gcd(b, a % b));
	}
}
int main() {
	int n;
	cin >> n;
	long long ans;
	cin >> ans;
	for (int i = 0; i < n - 1; i++) {
		long long a;
		cin >> a;
		ans = gcd(ans, a);
	}
	cout << ans << endl;
}
