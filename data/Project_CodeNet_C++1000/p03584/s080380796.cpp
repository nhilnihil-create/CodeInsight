#include <algorithm>
#include <bitset>
#include <cfloat>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps LDBL_EPSILON
#define mod 1000000007
#define int long long
#define double long double
#define INF LLONG_MAX/10
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int n, k, a[100010], b[100010];
signed main() {
	cin >> n >> k;
	rep(i, n)cin >> a[i] >> b[i];
	int ans = 0;
	rep(i, 35) {
		int memo;
		memo = ((k >> i) << i) + (((ll)1 << (i-1)) - 1);
		if (memo > k)continue;
		int cnt = 0;
		rep(j, n) {
			if ((a[j] | memo) == memo)cnt += b[j];
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}