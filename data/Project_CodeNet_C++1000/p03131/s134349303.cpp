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
	ll k, a, b;
	cin >> k >> a >> b;
	k++;
	if (b <= a + 1) {
		cout << k << endl;
	} else {
		if (k <= a + 1) {
			cout << k << endl;
		} else {
			k -= a + 2;
			ll op = k / 2;
			ll ret = b + op * (b - a);
			if (k & 1) {
				ret++;
			}
			cout << ret << endl;
		}
	}

	return 0;
}
