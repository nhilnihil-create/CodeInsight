#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>

using namespace std;
typedef long long ll;

bitset<4000001> bset, _bset;

int main() {
	int N; cin >> N;
	
	bset.reset();
	_bset.reset();

	int sum = 0;
	bset[0] = true;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		sum += a;

		_bset = bset << a;
		bset |= _bset;
	}

	for (int k = (sum + 1) / 2; k <= sum; k++) {
		if (bset[k] == true) {
			cout << k << endl;
			return 0;
		}
	}


	return 0;
}