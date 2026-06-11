#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int ans = a - 1;
	ans += a <= b ? 1: 0;
	cout << ans << endl;
	return 0;
}
