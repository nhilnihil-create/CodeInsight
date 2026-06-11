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

#define MAXN (1 << 21)

int n, q;
string s;

char a[MAXN];	

ll solve(int k) {
	ll ret = 0;
	int pos = k - 1;
	int nd = 0;
	int nm = 0;
	ll sum = 0;
	for (int i = k; i < n; i++) {
		char drop = a[i - k];
		if (drop == 'D') {
			nd--;
			sum -= nm;
		} else if (drop == 'M') {
			nm--;
		}
		if (a[i] == 'D') {
			nd++;
		} else if (a[i] == 'M') {
			nm++;
			sum += nd;
		} else if (a[i] == 'C') {
			ret += sum;
		}
	}
	return ret;
}

int main() {
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		a[i] = 'A';
	}
	for (int i = n; i < n + n; i++) {
		a[i] = s[i - n];
	}
	n *= 2;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		cout << solve(t) << endl;
	}
	return 0;
}
