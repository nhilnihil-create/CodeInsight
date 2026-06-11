#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;


	vector<int> east(n, 0), west(n, 0);
	int x = 0;
	for (int i = 0; i < n; i++) {
		west[i] = x;
		if (s[i] == 'W') {
			x++;
		}
	}
	x = 0;
	for (int i = n-1; i >= 0; i--) {
		east[i] = x;
		if (s[i] == 'E') {
			x++;
		}
	}

	int ans = 1e9;
	for (int i = 0; i < n; i++) {
		// printf("%2d %c: %d %d\n", i, s[i], west[i], east[i]);
		ans = min(ans, west[i] + east[i]);
	}
	cout << ans << endl;
	return 0;
}
