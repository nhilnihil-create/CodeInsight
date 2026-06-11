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
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;


int main() {
	int n;
	cin >> n;
	ll A[n];
	rep(i, n) cin >> A[i];
	rep(i, n) A[i] -= i+1;

	sort(A, A+n);
	ll res = 0;
	rep(i, n) {
		ll diff = abs(A[i] - A[n/2]);
		res += diff;
	}
	cout << res << endl;
}