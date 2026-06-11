#include <iostream>
#include <string>
#include <algorithm>
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
int co[1000][1000] = { 0 };
int main() {
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		int l, r;
		cin >> l >> r;
		co[l][r]++;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			co[i][j] += co[i - 1][j] + co[i][j - 1];
			co[i][j] -= co[i - 1][j - 1];
		}
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		cout << co[r][r] - co[r][l - 1] - co[l - 1][r] + co[l - 1][l - 1] << endl;
	}
	return 0;
}
