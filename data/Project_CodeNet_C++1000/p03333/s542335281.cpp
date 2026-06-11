#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const long long inf = 11451419198109130;
typedef pair<int, int> P;
typedef pair<P, int> PP;
typedef pair<int, PP> PPP;
struct edge { int to; int to2; int cost; };
int l[100005], r[100005];
vector<int>L,R;
int u[100005];
signed main() {
	int n; cin >> n;
	rep(i, n)cin >> l[i] >> r[i];
	sort(l, l + n);
	reverse(l, l + n);
	sort(r, r + n);
	int res = 0;
	int sum = 0;
	rep(i,n) {
		sum += 2 * l[i];
		res = max(sum, res);
		sum += -2 * r[i];
		res = max(sum, res);
	}
	sum = 0;
	rep(i, n) {
		sum += -2 * r[i];
		res = max(sum, res);
		sum += 2 * l[i];
		res = max(sum, res);
	}
	cout << res << endl;
}