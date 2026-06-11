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
#define INF INT_MAX
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int n, m, a, b;
vector<int> vec[100010];
int d[100010];
bool dfs(int node, bool f) {
	if (!f)d[node] = 1;
	else d[node] = 2;
	for (int i : vec[node]) {
		if (d[node] == d[i])return false;
		if (!d[i] && !dfs(i, !f))return false;
	}
	return true;
}
signed main() {
	cin >> n >> m;
	rep(i, m) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	if (!dfs(1, 0))cout << n * (n - 1) / 2 - m << endl;
	else {
		int cnt = 0;
		REP(i, n)if (d[i] == 1)cnt++;
		cout << cnt * (n - cnt) - m << endl;
	}
}