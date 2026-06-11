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
	int N;
	cin >> N;
	int64_t A[110];
	rep(i, N) cin >> A[i];

	sort(A, A+N);
	int64_t res = A[N-1] - A[0];
	cout << res << endl;
}