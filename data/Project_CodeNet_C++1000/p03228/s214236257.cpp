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
	ll a, b, k;
	cin >> a >> b >> k;
	REP(i, k) {
		if (i % 2 == 0) {
			if (a % 2 == 1) {
				a--;
			}
			b += a / 2;
			a /= 2;
		}
		else {
			if (b % 2 == 1) {
				b--;
			}
			a += b / 2;
			b /= 2;
		}
	}
	cout << a << " " << b << endl;
	return 0;
}