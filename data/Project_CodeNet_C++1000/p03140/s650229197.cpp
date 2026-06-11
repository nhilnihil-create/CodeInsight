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

	int n, i, j, k, ans = 0;
	vector<string> s(3);
	cin >> n >> s[0] >> s[1] >> s[2];
	for (i = 0; i < n; i++) {
		set<char> ct;
		ct.insert(s[0][i]);
		ct.insert(s[1][i]);
		ct.insert(s[2][i]);

		if (ct.size() == 3) ans += 2;
		else if (ct.size() == 2) ans += 1;
	}
	cout << ans << "\n";

	return 0;
}

