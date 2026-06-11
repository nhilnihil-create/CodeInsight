#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <numeric>
#include <bitset>
#include <ext/algorithm>
#include <ext/numeric>
#define ffor(_a,_f,_t) for(int _a=(_f),__t=(_t);_a<__t;_a++)
#define all(_v) (_v).begin() , (_v).end()
#define sz size()
#define pb push_back
#define SET(__set, val) memset(__set, val, sizeof(__set))
#define FOR(__i, __n) ffor (__i, 0, __n)
typedef long long LL; using namespace std;

LL findRoot(LL x) {
	LL s = 0LL, e = 1100000000LL, mid;
	LL ret = -1;
	while (s <= e) {
		mid = (s + e) >> 1;
		if (1LL * mid * mid <= x) {
			ret = mid;
			s = mid + 1LL;
		}
		else
			e = mid - 1LL;
	}
	return ret;
}

int main() {
	int t;
	cin >> t;
	LL A, B;
	FOR (test, t) {
		cin >> A >> B;
		if (A > B)
			swap(A, B);
		LL ret;
		if (A == B || A + 1LL == B)
			ret = 2LL * A - 2LL;
		else {
			LL C = findRoot(A * B - 1LL);
			//LL C = sqrt(A * B);
			//if (C * C == A * B)
				//C--;
			if (C * (C + 1LL) >= A * B)
				ret = 2LL * C - 2LL;
			else
				ret = 2LL * C - 1LL;
		}
		cout << ret << endl;
	}
  return 0;
}