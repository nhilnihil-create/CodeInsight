#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const double pi = 3.1415926535897932;
const double eps = 0.000000000001;
const int inf = 1145141919;
struct edge { int to, cost; };
typedef pair<int, int>P;
typedef pair<int, P> PP;
int a[200005], b[200005];
signed main() {
	int n; cin >> n;
	rep(i, n)cin >> a[i]>>b[i];
	int cnt = 0;
	rep(i, n)if (a[i] == b[i])cnt++;
	if (cnt == n)puts("0");
	else {
		cnt = 0;
		rep(i, n)cnt += a[i];
		int mn = inf;
		rep(i, n) {
			if (a[i] > b[i])mn = min(mn, b[i]);
		}

		cout << cnt-mn << endl;
	}
}