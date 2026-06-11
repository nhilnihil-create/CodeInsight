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
using ll = long long;


int main() {
	int n;
	cin >> n;
	int A[n+2];
	A[0] = 0;
	A[n+1] = 0;
	for (int i=1; i<=n; i++) cin >> A[i];
	int sum = 0;
	rep(i, n+1) {
		int diff = abs(A[i+1] - A[i]);
		sum += diff;
	}
	for (int i=1; i<=n; i++) {
		int diff_m = abs(A[i+1] - A[i]) + abs(A[i-1] - A[i]);
		int diff_p = abs(A[i+1] - A[i-1]);
		int res = sum - diff_m + diff_p;
		cout << res << endl;
	}
}