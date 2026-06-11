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

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, k, i, j, t, d, ans, kk;
	cin >> n >> k;
	vector<vector<long long>> plist(n + 1);
	for (i = 0; i < n; i++) {
		cin >> t >> d;
		plist[t].push_back(d);
	}

	priority_queue<long long> p1, p2;
	for (i = 1; i <= n; i++) {
		if (!plist[i].empty()) {
			sort(plist[i].rbegin(), plist[i].rend());
			p1.push(plist[i][0]);
			for (j = 1; j < plist[i].size(); j++) p2.push(plist[i][j]);
		}
	}

	ans = 0; kk = k;
	for (i = 0; i < k; i++) {
		if (!p1.empty() && ((i == 0) || (p2.empty()) || (p2.top() - (kk + kk - 1) <= p1.top()))) {
			ans += p1.top();
			p1.pop();
		}
		else {
			ans += p2.top();
			p2.pop();
			kk--;
		}
	}
	ans += kk * kk;
	cout << ans << "\n";

	return 0;
}