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

int d[4];

int main() {
	for (int i = 0; i < 3; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--;
		v2--;
		d[v1]++;
		d[v2]++;
	}
	sort(d, d + 4);
	if ((d[0] == 1) && (d[1] == 1) && (d[2] == 2) && (d[3] == 2)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}
