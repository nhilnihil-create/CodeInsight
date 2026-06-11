#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include<math.h>
#include <vector>
#include<bitset>
using namespace std;

int main() {
	int n, q; string s; cin >> n >> q >> s;
	vector<int>sum(n, 0);
	bool a = 0;
	for (int i = 0; i < n; i++) {
		if (a && s[i] == 'C') {
			sum[i] = 1 + sum[i - 1]; a = 0;
		}
		else if (s[i] == 'A') {
			sum[i] = sum[i - 1]; a = 1; continue;
		}
		else {
			sum[i] = sum[i - 1]; a = 0;
		}
	}
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		cout << sum[r - 1] - sum[l - 1] << endl;
	}
}