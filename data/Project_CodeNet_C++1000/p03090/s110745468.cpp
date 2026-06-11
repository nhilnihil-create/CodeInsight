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

	int n, i, j, k;
	cin >> n;
	vector<vector<bool>> c(n, vector<bool>(n, false));

	if (n % 2 == 0) {
		for (i = 0; i < n / 2; i++) {
			c[i][n - 1 - i] = true;
			c[n - 1 - i][i] = true;
		}
	}
	else {
		for (i = 0; i < n / 2; i++) {
			c[i][n - 2 - i] = true;
			c[n - 2 - i][i] = true;
		}
	}

	vector<pair<int, int>> ans;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (!c[i][j]) ans.push_back({ i, j });
		}
	}

	cout << ans.size() << "\n";
	for (auto p : ans) cout << p.first + 1 << " " << p.second + 1 << "\n";


	return 0;
}

