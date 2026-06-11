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
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;


int main() {
	int n, m;
	cin >> n >> m;
	int min_g = 0;
	int max_g = 100000;
	rep(i, m) {
		int l, r;
		cin >> l >> r;
		if (l>min_g) min_g = l;
		if (r<max_g) max_g = r;
	}
	if (max_g >= min_g) {
		cout << max_g - min_g + 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
}