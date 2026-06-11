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

	int n, i, j, k, x, ans = 13, ct;
	cin >> n;
	vector<int> a(13, 0), xx;
	for (i = 0; i < n; i++) {
		cin >> x;
		a[x]++;
		ans = min(ans, x);
	}
	xx.push_back(0);
	ct = 0;
	for (i = 0; i < 13; i++) {
		if (a[i] == 0) continue;
		if (a[i] >= 2) {
			xx.push_back(i);
			xx.push_back(24-i);
		}
		else {
			ct++;
			if (ct % 2 == 0) xx.push_back(i);
			else xx.push_back(24-i);
		}

		if (a[i] >= 3) ans = 0;
	}
	xx.push_back(24);
	
	//for (i = 1; i < xx.size(); i++) ans = min(ans, xx[i] - xx[i - 1]);
	//for (i = 1; i < yy.size(); i++) ans = min(ans, abs(yy[i] - yy[i - 1]));
	//if (xx[xx.size() - 1] != 12) ans = min(ans, 24 - (xx[xx.size() - 1] - yy[yy.size() - 1]));
	//if (a[12] > 1) ans = 0;

	sort(xx.begin(), xx.end());
	for (i = 1; i < xx.size(); i++) ans = min(ans, xx[i] - xx[i - 1]);

	cout << ans << "\n";

	return 0;
}


