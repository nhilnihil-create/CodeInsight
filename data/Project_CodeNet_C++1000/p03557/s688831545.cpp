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
	vector<ll> A(n), B(n), C(n);
	rep(i, n) cin >> A[i];
	rep(i, n) cin >> B[i];
	rep(i, n) cin >> C[i];
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());

	ll idx_bound_A, idx_bound_C;
	ll res = 0;
	rep(i, n) {
		ll key = B[i];
		ll numA, numC;
		auto lower = lower_bound(A.begin(), A.end(), key);
		idx_bound_A = distance(A.begin(), lower);
		if (lower==A.end()) {
			numA = n;
		}
		else numA = idx_bound_A;

		auto upper = upper_bound(C.begin(), C.end(), key);
		idx_bound_C = distance(C.begin(), upper);
		if (upper==C.end()) {
			numC = 0;
		}
		else numC = n - idx_bound_C;
		res += numA * numC;
	}
	cout << res << endl;
}