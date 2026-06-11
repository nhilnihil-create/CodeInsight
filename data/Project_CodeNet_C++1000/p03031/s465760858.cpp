#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;


int main() {
	int n, m;
	cin >> n >> m;

	vector<int> k(m);
	vector<vector<int>> s(m, vector<int>(n));
	vector<int> p(m);

	for (int i = 0;i < m;i++) {
		cin >> k[i];
		for (int j = 0;j < k[i];j++) {
			cin >> s[i][j];
		}
	}

	for (int i = 0;i < m;i++) {
		cin >> p[i];
	}

	int ans = 0;
	vector<int> on(n);
	for (int b = 0;b < (1 << n);b++) {
		for (int a = 0;a < n;a++) {
			if (b & (1 << a)) on[a] = 1;
			else on[a] = 0;
		}

		int flag = 0;

		for (int i = 0;i < m;i++) {
			int sum = 0;

			for (int j = 0;j < k[i];j++) {
				if (on[s[i][j] - 1] == 1) sum++;
			}

			if (sum % 2 != p[i]) {
				flag = 1;
				break;
			}
		}

		if (flag == 0) ans++;
	}
	
	cout << ans << endl;

	return 0;
}
