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
	int A[n];
	int B[n];
	rep(i, n) cin >> A[i];
	rep(i, n) cin >> B[i];

	int ans = 0;
	if (n==1) {
		cout << A[0]+B[0] << endl;
		return 0;
	}
	for (int i=0; i<n; i++) {
		for (int j=i; j<n; j++) {
			int sum = accumulate(A, A+i, 0) + accumulate(B+i-1, B+n, 0);
			ans = max(sum, ans);
		}
	}
	cout << ans << endl;
}