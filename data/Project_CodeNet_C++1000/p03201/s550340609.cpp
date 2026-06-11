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

	long long n, i, j, k, maxx, x, y, ans = 0;
	cin >> n;
	map<long long, long long> s;
	for (i = 0; i < n; i++) {
		cin >> x;
		s[x]++;
	}

	while (!s.empty()) {
		x = s.rbegin()->first;
		if (s[x] == 1) s.erase(x);
		else s[x]--;

		for (i = 1; i < 32; i++) {
			y = (1LL << i) - x;
			if (s.find(y) != s.end()) {
				ans++;
				if (s[y] == 1) s.erase(y);
				else s[y]--;
			}
		}
	}


	cout << ans << "\n";

	return 0;
}

