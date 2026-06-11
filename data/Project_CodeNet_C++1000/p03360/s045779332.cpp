#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>

using namespace std;

int main() {
	int a, b, c, k;
	cin >> a >> b >> c >> k;

	vector<int> v = {a, b, c};
	sort(v.begin(), v.end());
	while (k > 0) {
		v[2] *= 2;
		k--;
	}

	int ans = v[0] + v[1] + v[2];
	cout << ans << endl;
	return 0;
}
