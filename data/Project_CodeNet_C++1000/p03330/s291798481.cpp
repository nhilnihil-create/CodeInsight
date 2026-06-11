#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define mod 1000000007

int main() {
	int n, c;
	cin >> n >> c;
	int d[30][30];
	int cnt[3][30] = {};
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			cin >> d[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			tmp--;
			cnt[(i + j) % 3][tmp]++;
		}
	}
	int ans = mod;
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			if (i == j) continue;
			for (int k = 0; k < c; k++) {
				if (i == k || j == k) continue;
				int res = 0;
				int now[3] = {i, j, k};
				for (int p = 0; p < 3; p++) {
					for (int q = 0; q < c; q++) {
						res += d[q][now[p]] * cnt[p][q];
					}
				}
				ans = min(ans, res);
			}
		}
	}
	cout << ans << endl;
}