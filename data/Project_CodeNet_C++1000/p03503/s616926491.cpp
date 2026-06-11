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
int f[110][11];
int p[110][12];
int b[10];
int main(){
	int n;
	int ans = -1000000007;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> f[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 11; j++) {
			cin >> p[i][j];
		}
	}
	for (int bit = 1; bit < (1 << 10); bit++) {
		for (int i = 0; i < 10; i++) {
			if (bit & (1 << i)) {
				b[i] = true;
			}
			else {
				b[i] = false;
			}
		}
		int sum = 0;
		for (int j = 0; j < n; j++) {
			int co = 0;
			for (int k = 0; k < 10; k++) {
				if (b[k] == true && f[j][k] == 1) {
					co++;
				}
			}
			sum += p[j][co];
		}
		if (sum > ans) {
			ans = sum;
		}
	}
	cout << ans << endl;

}