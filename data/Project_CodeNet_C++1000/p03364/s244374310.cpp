#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cfloat>
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
int n;
char s[310][310], b[310][310];
bool check() {
	rep(i, n) {
		rep(j, n) {
			if (b[i][j] != b[j][i])return false;
		}
	}
	return true;
}
signed main() {
	cin >> n;
	rep(i, n) {
		rep(j, n)cin >> s[i][j];
	}
	int ans = 0;
	rep(i, n) {
		rep(j, n) {
			rep(k, n)b[j][k] = s[j][(k + i) % n];
		}
		if (check())ans++;
	}
	cout << ans * n << endl;
	return 0;
}