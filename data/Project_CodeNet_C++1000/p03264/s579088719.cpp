#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int k; cin >> k;
	int o = 0, e = 0;
	for (int i = 1; i <= k; i++) {
		if (i & 1) o++;
		else e++;
	}
	cout << o * e << '\n';
}