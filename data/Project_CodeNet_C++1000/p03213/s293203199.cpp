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
	int n;
	int co[100] = { 0 };
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int i1 = i;
		for (int j = 2; j <= n; j++) {
			if (i1 % j == 0) {
				while (1) {
					if (i1 % j != 0) {
						break;
					}
					i1 /= j;
					co[j]++;
				}
			}
		}
	}
	int ans = 0, ans1 = 0;
	for (int i = 0; i < 100; i++) {
		if (co[i] >= 74) {
			ans++;
		}
		if (co[i] >= 24) {
			for (int j = 0; j < 100; j++) {
				if (i == j) {
					continue;
				}
				if (co[j] >= 2) {
					ans++;
				}
			}
		}
		if (co[i] >= 14) {
			for (int j = 0; j < 100; j++) {
				if (i == j) {
					continue;
				}
				if (co[j] >= 4) {
					ans++;
				}
			}
		}
		if (co[i] >= 4) {
			for (int j = 0; j < 100; j++) {
				if (i == j) {
					continue;
				}
				if (co[j] >= 4) {
					for (int k = 0; k < 100; k++) {
						if (i == k || j == k) {
							continue;
						}
						if (co[k] >= 2) {
							ans1++;
						}
					}
				}
			}
		}
	}
	cout << ans1 / 2 + ans << endl;
	return 0;
}