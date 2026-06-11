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
#include <bitset>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;


int main() {
	int n;
	cin >> n;
	int C[n-1], S[n-1], F[n-1];
	rep(i, n-1) {
		cin >> C[i] >> S[i] >> F[i];
	}

	for (int i=0; i<n-1; i++) {
		int res = 0;
		for (int j=i; j<n-1; j++) {
			if (j==i) {
				res += S[j] + C[j];
			}
			else {
				int w = S[j];
				while (res>w) w += F[j];
				res += w-res+C[j];
			}
		}
		cout << res << endl;
	}
	cout << 0 << endl;
}