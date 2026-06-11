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
int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> vec;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec.emplace_back(make_pair(a, b));
	}
	sort(vec.begin(), vec.end());
	int co = 1;
	int l = vec[0].first, r = vec[0].second;
	for (int i = 1; i < m; i++) {
		if (r <= vec[i].first) {
			co++;
			l = vec[i].first;
			r = vec[i].second;
		}
		if (r > vec[i].second) {
			r = vec[i].second;
		}
		if (l < vec[i].first) {
			l = vec[i].first;
		}
	}
	cout << co << endl;
	return 0;
}
