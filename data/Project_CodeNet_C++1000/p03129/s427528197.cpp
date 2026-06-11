#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <map>
#include <utility>
#include <numeric>
#define ll long long
#define REP(i, x) for(int (i) = 0; (i) < (x); (i) ++)
#define pi 3.1415926535
const int MOD = 1000000007;
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	if (2 * k - 1 <= n) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}