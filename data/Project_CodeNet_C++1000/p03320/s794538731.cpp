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

ll digitsum(ll i) {
	ll d = 0;
	while (i > 0) { d += i % 10; i /= 10; }
	return d;
}
int main() {
	double m = 0;
	int K; cin >> K;
	ll x = 0;
	ll d = 1;
	ll table[16] = {
		1,
		10,
		100,
		1000,
		10000,
		100000,
		1000000,
		10000000,
		100000000,
		1000000000,
		10000000000,
		100000000000,
		1000000000000,
		10000000000000,
		100000000000000,
		1000000000000000
	};
	double s[16];
	for (int c = 0; c < K; c++) {
		for (int i = 0; i < 16; i++) {
			s[i] = (double)(x + table[i]) / (double)digitsum(x + table[i]);
		}
		int k = 0;
		double b = s[0];
		for (int i = 1; i < 16; i++) {
			if (b > s[i]) {
				b = s[i];
				k = i;
			}
		}
		x += table[k];
		cout << x << endl;
	}
	return 0;
}
