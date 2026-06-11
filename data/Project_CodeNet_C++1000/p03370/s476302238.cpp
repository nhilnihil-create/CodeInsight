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
	int N, X;
	cin >> N >> X;
	int A[1010];
	rep(i, N) cin >> A[i];

	sort(A, A+N);
	int sum = accumulate(A, A+N, 0);
	int ans = N;
	bool flg = true;
	while (flg) {
		sum += A[0];
		if (X-sum<0) flg = false;
		else ans++;
	}
	cout << ans << endl;
}