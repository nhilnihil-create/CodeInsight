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
int main(){
	long long n, m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 1; i * i <= m; i++) {
		if (m % i == 0) {
			if (i * n <= m) {
				if (ans < i) {
					ans = i;
				}
			}
			if ((m / i) * n <= m) {
				if (ans < (m / i)) {
					ans = (m / i);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}

