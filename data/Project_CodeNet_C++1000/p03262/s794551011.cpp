#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
	while (a % b != 0 && b % a != 0) {
		if (a > b) {
			a %= b;
		} else {
			b %= a;
		}
	}
	return min(a, b);
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n + 1, 0);
	for (int i = 0; i <= n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		v[i] = v[i + 1] - v[i];
	}
	v.pop_back();
	int res = v[0];
	for (int i = 1; i < n; i++) {
		res = gcd(res, v[i]);
	}
	cout << res << endl;
}
