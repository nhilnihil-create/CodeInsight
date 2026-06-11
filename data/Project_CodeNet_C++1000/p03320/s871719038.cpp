#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cfloat>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps LDBL_EPSILON
#define mod (ll)1000000007
#define INF LLONG_MAX/10
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int k;
int digitsum(int n) {
	int res = 0;
	while (n) {
		res += n % 10;
		n /= 10;
	}
	return res;
}
int mypow(int a, int b) {
	if (!b)return 1;
	if (b % 2)return mypow(a, b - 1) * a;
	int memo = mypow(a, b / 2);
	return memo * memo;
}
bool func(int a, int b) {
	if (a * digitsum(b) == b * digitsum(a))return a < b;
	return a * digitsum(b) < b * digitsum(a);
}
signed main() {
	cin >> k;
	vector<int> vec;
	REP(i, 99)vec.push_back(i);
	rep(i, 13) {
		int n = mypow(10, i) - 1;
		for (int j = 100; j <= 999; j++) {
			vec.push_back(n + j * mypow(10, i));
		}
	}
	sort(vec.begin(), vec.end(), func);
	int ma = 0, cnt = 0, i = 0;
	while (true) {
		if (ma >= vec[i]) {
			i++;
			continue;
		}
		cout << vec[i] << endl;
		cnt++;
		ma = max(ma, vec[i]);
		i++;
		if (cnt == k)break;
	}
	return 0;
}