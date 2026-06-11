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
#define int long long
	int n;
	cin >> n;
	int x[110], y[110], h[110];
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> h[i];
	}
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			int t = 1000000000000000000;
			for (int k = 0; k < n; k++) {
				if (h[k] != 0) {
					t = h[k] + abs(i - x[k]) + abs(j - y[k]);
					break;
				}
			}
			bool b = true;
			if (t == 0) {
				continue;
			}
			else {
				for (int k = 0; k < n; k++) {
					if (h[k] == 0) {
						if (h[k] + abs(i - x[k]) + abs(j - y[k]) < t) {
							b = false;
						}
					}
					else {
						if (h[k] + abs(i - x[k]) + abs(j - y[k]) != t) {
							b = false;
						}
					}
				}
			}
			if (b == true) {
				cout << i << " " << j << " " << t << endl;
				return 0;
			}
		}
	}
	return 0;
}

