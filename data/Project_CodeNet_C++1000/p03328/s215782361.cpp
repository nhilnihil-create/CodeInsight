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
	int diff = b - a;
	int h = diff * (diff + 1) / 2;
	int ans = h - b;
	cout << ans << endl;
	return 0;
}
