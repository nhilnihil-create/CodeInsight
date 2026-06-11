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

int main() {
	int K; cin >> K;
	ll* A = new ll[K];
	for (int i = K - 1; i >= 0; i--) {
		cin >> A[i];
	}

	if (A[0] != 2) {
		cout << "-1" << endl;
		return 0;
	}

	ll m = 2, M = 2;

	for (int i = 0; i < K; i++) {
		m = ((m + A[i] - 1) / A[i]) * A[i];
		M = (M - M % A[i]) + A[i] - 1;
		if (M < m) { cout << "-1" << endl; return 0; }
	}

	cout << m << " " << M << endl;

	return 0;
}