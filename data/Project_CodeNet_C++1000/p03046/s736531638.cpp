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
	int M, K; cin >> M >> K;
	int N = 1 << M;
	if (N <= K) {
		cout << -1 << endl;
		return 0;
	}

	if (M == 0) {
		if (K == 0) {
			cout << "0 0" << endl;
		}
		else {
			cout << -1 << endl;
		}
		return 0;
	}
	if (M == 1) {
		if (K == 0) {
			cout << "0 0 1 1" << endl;
		}
		else {
			cout << -1 << endl;
		}
		return 0;
	}
	
	cout << K << " ";
	for (int i = 0; i < N; i++) {
		if (i == K) {
			continue;
		}
		cout << i << " ";
	}
	cout << K << " ";
	for (int i = N - 1; i >= 0; i--) {
		if (i == K) {
			continue;
		}
		cout << i << " ";
	}
	cout << endl;

	return 0;
}