#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <random>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i, j, k, nn;
	cin >> n;
	nn = 1 << n;

	vector<pair<int, int>> a(nn);
	for (i = 0; i < nn; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	vector<set<pair<int, int>>> s(nn);
	vector<int> ans(nn, 0);
	for (i = 0; i < nn; i++) {
		s[i].insert(a[i]);

		for (j = 0; j < n; j++) {
			if ((1 << j) & i) {
				for (auto p : s[i - (1 << j)]) s[i].insert(p);
			}
		}
		while (s[i].size() > 2) s[i].erase(s[i].begin());

		if (i > 0) {
			ans[i] = max(ans[i - 1], s[i].begin()->first + s[i].rbegin()->first);
			cout << ans[i] << "\n";
		}
	}



	return 0;
}
