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


int main() {
	int n, T;
	cin >> n >> T;
	int res = -1;
	for (int i = 0; i < n; i++) {
		int c, t;
		cin >> c >> t;
		if (t <= T) {
			if (res == -1 || res > c) {
				res = c;
			}
		}
	}
	if (res == -1) {
		cout << "TLE";
	} else {
		cout << res;
	}
	cout << endl;
}
