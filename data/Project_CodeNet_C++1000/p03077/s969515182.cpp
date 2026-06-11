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
	int64_t n;
	int64_t A[5];
	cin >> n;
	rep(i, 5) cin >> A[i];

	int64_t mn = *min_element(A, A+5);
	int64_t ans = (n-1)/mn + 5;
	cout << ans << endl;
}