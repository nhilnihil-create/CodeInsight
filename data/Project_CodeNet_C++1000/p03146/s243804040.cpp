#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	vector<bool> memo(10000001, false);
	int s;
	cin >> s;
	memo[s] = true;
	for (int i = 1; i <= 10000001; i++) {
		s = (s % 2 == 0) ? s / 2 : 3 * s + 1;
		if (memo[s]) {
			cout << i+1 << endl;
			return 0;
		}
		memo[s] = true;
	}
	return 0;

}