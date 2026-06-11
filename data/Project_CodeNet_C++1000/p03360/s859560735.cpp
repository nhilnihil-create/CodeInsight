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
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)


int main() {
	int A[10];
	int K;
	rep(i, 3) cin >> A[i];
	cin >> K;

	rep(i, K) {
		sort(A, A+3, greater<int>());
		A[0] *= 2;
	}
	int ans = accumulate(A, A+3, 0);
	cout << ans << endl;
}