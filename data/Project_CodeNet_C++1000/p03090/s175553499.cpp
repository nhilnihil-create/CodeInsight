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
vector<pair<int, int>> vec, ans;
int main(){
	int n;
	cin >> n;
	if (n % 2 == 0) {
		for (int i = 1; i <= n / 2; i++) {
			vec.emplace_back(make_pair(i, n - i + 1));
		}
	}
	else {
		for (int i = 1; i <= n / 2; i++) {
			vec.emplace_back(make_pair(i, n - i));
		}
	}
	sort(vec.begin(), vec.end());
	int co = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (co >= vec.size()) {
				ans.emplace_back(make_pair(i, j));
			}
			else if (i == vec[co].first && j == vec[co].second) {
				co++;
				continue;
			}
			else {
				ans.emplace_back(make_pair(i, j));
			}
		}
	}
	cout << ans.size() << endl;
	for (int k = 0; k < ans.size(); k++) {
		cout << ans[k].first << " " << ans[k].second << endl;
	}
	return 0;
}