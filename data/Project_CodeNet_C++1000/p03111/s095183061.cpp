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
int n, a, b, c;
int l[10];
int ans = 1000000007;
void dfs(vector<int>v) {
	if (v.size() == n) {
		int sa = 0, sb = 0, sc = 0, co = 0;
		bool bo = false, bo1 = false, bo2 = false;
		for (int i = 0; i < n; i++) {
			if (v[i] == 1) {
				sa += l[i];
				if (bo) {
					co += 10;
				}
				bo = true;
			}
			if (v[i] == 2) {
				sb += l[i];
				if (bo1) {
					co += 10;
				}
				bo1 = true;
			}
			if (v[i] == 3) {
				sc += l[i];
				if (bo2) {
					co += 10;
				}
				bo2 = true;
			}
		}
		if (bo && bo1 && bo2) {
			if (abs(sa - a) + abs(sb - b) + abs(sc - c) + co < ans) {
				ans = abs(sa - a) + abs(sb - b) + abs(sc - c) + co;
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		v.emplace_back(i);
		dfs(v);
		v.pop_back();
	}
}
int main() {
	cin >> n >> a >> b >> c;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	vector<int> vec;
	dfs(vec);
	cout << ans << endl;
	return 0;
}
