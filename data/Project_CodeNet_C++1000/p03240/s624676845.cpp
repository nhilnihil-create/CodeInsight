#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <bitset>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;


int main() {
	int n;
	cin >> n;
	int x[110], y[110], h[110];
	rep (i, n) {
		cin >> x[i] >> y[i] >> h[i];
		if (h[i]>0) {
			swap(x[i], x[0]);
			swap(y[i], y[0]);
			swap(h[i], h[0]);
		}
	}
	for (int cx=0; cx<=100; cx++) {
		for (int cy=0; cy<=100; cy++) {
			bool flg = true;
			int base_h = h[0] + abs(cx-x[0]) + abs(cy-y[0]);
			for (int i=1; i<n; i++) {
				if (max(base_h-abs(cx-x[i])-abs(cy-y[i]), 0) != h[i]) {
					flg = false;
					break;
				}
			}
			if (flg) {
				cout << cx << " " << cy << " " << base_h << endl;
				return 0;
			}
		}
	}
}