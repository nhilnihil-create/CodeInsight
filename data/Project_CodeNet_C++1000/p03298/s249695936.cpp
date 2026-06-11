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
#define mod 10000000
#define int long long
#define double long double
#define INF LLONG_MAX/10
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int n;
string s;
map<pair<string, string>, int> mp[2];
signed main() {
	cin >> n >> s;
	reverse(s.begin() + n, s.end());
	rep(i, ((ll)1 << n)) {
		string t, r;
		rep(j, n) {
			if ((i >> j) & 1)t += s[j];
			else r += s[j];
		}
		mp[0][make_pair(t, r)]++;
	}

	rep(i, ((ll)1 << n)) {
		string t, r;
		rep(j, n) {
			if ((i >> j) & 1)t += s[j + n];
			else r += s[j + n];
		}
		mp[1][make_pair(t, r)]++;
	}
	int ans = 0;
	for (auto p : mp[0]) {
		ans += mp[1][p.first] * p.second;
	}
	cout << ans << endl;
	return 0;
}