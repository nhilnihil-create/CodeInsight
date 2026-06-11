#include <bit>
#include <bitset>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>


typedef long double ld;
typedef long long ll;

using namespace std;

int main() {
	vector<int> a;
	for (int i = 0; i < 4; i++) {
		int t;
		cin >> t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	if (a[0] == 1 && a[1] == 4 && a[2] == 7 && a[3] == 9) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
