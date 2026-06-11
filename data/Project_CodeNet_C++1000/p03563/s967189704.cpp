#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
	int r, g;
	cin >> r >> g;

	int ans = r + (g - r) * 2;
	cout << ans << endl;
	return 0;
}
