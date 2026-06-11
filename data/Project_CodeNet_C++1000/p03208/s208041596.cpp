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
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)


int main() {
	int n, k;
	cin >> n >> k;
	int A[n];
	rep(i, n) cin >> A[i];
	sort(A, A+n);

	int res = 1000000000;
	rep(i, n-k+1) {
		int d = A[i+k-1] - A[i];
		res = min(res, d);
	}
	cout << res << endl;
}