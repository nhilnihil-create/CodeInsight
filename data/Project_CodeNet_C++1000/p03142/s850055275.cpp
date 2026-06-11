#include <algorithm>
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
#define INF LLONG_MAX/1000
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int n, m, a[100010], b[100010], c[100010];
vector<int> vec[100010], ans;
set<int> res[100010];
bool used[100010];
void visit(int node) {
	if (!used[node]) {
		used[node] = true;
		for (int i : vec[node])visit(i);
		ans.push_back(node);
	}
}
signed main() {
	cin >> n >> m;
	rep(i, n + m - 1) {
		cin >> a[i] >> b[i];
		vec[a[i]].push_back(b[i]);
	}
	REP(i, n)visit(i);
	reverse(ans.begin(), ans.end());
	rep(i, n)c[ans[i]] = i;
	rep(i, n + m - 1)res[c[b[i]]].insert(c[a[i]]);
	REP(i, n) {
		if (!res[c[i]].empty())cout << ans[*res[c[i]].rbegin()] << endl;
		else cout << 0 << endl;
	}
	return 0;
}