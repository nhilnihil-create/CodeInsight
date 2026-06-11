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
vector<vector<int>> vec(11);
int main() {
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int s;
			cin >> s;
			vec[i].emplace_back(s - 1);
		}
	}
	int p[11];
	for (int i = 0; i < m; i++) {
		cin >> p[i];
	}
	bool b[11];
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				b[j] = true;
			}
			else {
				b[j] = false;
			}
		}
		int co = 0;
		for (int j = 0; j < m; j++) {
			int co1 = 0;
			for (int k = 0; k < vec[j].size(); k++) {
				if (b[vec[j][k]]) {
					co1++;
				}
			}
			if (co1 % 2 == p[j] % 2) {
				co++;
			}
		}
		if (co == m) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}