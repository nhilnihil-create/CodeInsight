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
	long long n;
	cin >> n;
	long long ans = 0;
	for (long long i = 1; i * i < n; i++) {
		if ((n - i) % i == 0 && (n - i) / i > i) {
			ans += (n - i) / i;
		}
	}
	cout << ans << endl;
	return 0;
}