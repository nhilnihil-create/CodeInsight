#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define N 200005

pair<int, int> in[N], tmp[N];

int per[N];
bool vis[N];
char s[N];

void solve() {
	scanf(" %s", s + 1);
	int n = strlen(s+1);
	map<int, int> minBitDp;
	minBitDp[0] = 0;
	int curBit = 0;
	for (int i = 1; i <= n; ++i) {
		curBit ^= (1 << (s[i] - 'a'));
		int mini = 1e9;
		if (minBitDp.count(curBit)) {
			mini = minBitDp[curBit];
		}
		for (int b = 0; b < 26; ++b) {
			int tbit = curBit ^ (1 << b);
			if (minBitDp.count(tbit)) {
				mini = min(mini, minBitDp[tbit]);
			}
		}
		++mini;
		if (i == n) {
			printf("%d\n", mini);
			return;
		}
		if (!minBitDp.count(curBit)) {
			minBitDp[curBit] = mini;
		}
		else {
			minBitDp[curBit] = min(minBitDp[curBit], mini);
		}
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}