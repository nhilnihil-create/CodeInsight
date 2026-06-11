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
int d[40][40];
int s[510][510];
int co1[40] = { 0 }, co2[40] = { 0 }, co3[40] = { 0 };
int main() {
	int n, c;
	long long min = 1000000000000007;
	cin >> n >> c;
	for (int a = 1; a <= c; a++) {
		for (int b = 1; b <= c; b++) {
			cin >> d[a][b];
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int l = 1; l <= n; l++) {
			cin >> s[k][l];
			if ((k + l) % 3 == 0) {
				co1[s[k][l]]++;
			}
			else if ((k + l) % 3 == 1) {
				co2[s[k][l]]++;

			}
			else {
				co3[s[k][l]]++;
			}
		}
	}
	for (int e = 1; e <= c; e++) {
		for (int f = 1; f <= c; f++) {
			if (e == f) continue;
			for (int g = 1; g <= c; g++) {
				if (e == g || f == g) continue;
				long long co = 0;
				for (int h = 1; h <= c; h++) {
					co += d[h][e] * co1[h];
					co += d[h][f] * co2[h];
					co += d[h][g] * co3[h];
				}
				
				if (min > co) {
					min = co;
				}
				co = 0;
			}
		}
	}
	printf("%lld\n", min);
	return 0;
}