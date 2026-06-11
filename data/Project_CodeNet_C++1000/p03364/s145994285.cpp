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
	
	int n, i, j, k, a, b, ans;
	cin >> n;
	vector<string> s(n + n);
	for (i = 0; i < n; i++) {
		cin >> s[i];
		s[i] = s[i] + s[i];
		s[i + n] = s[i];
	}

	ans = 0;
	for (i = 0; i < n; i++) {
		bool valid = true;
		vector<string> ss(n);
		for (j = 0; j < n; j++) ss[j] = s[j].substr(i, n);
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				if (ss[j][k] != ss[k][j]) valid = false;
			}
		}

		if (valid) ans += n;
	}

	cout << ans << "\n";

	return 0;
}
