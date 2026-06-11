#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pf(n) printf("%lld\n",n)
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> l(m);
	vector<int> r(m);
	rep(i, m) cin >> l[i] >> r[i];

	int left = 0;
	rep(i, m) {
		left = max(left, l[i]);
	}
	int right = 100100;
	rep(i, m) {
		right = min(right, r[i]);
	}
	int ans = 0;
	for (int i = left; i <= right; i++) {
		if (i > n) break;
		ans++;
	}
	cout << ans << endl;

	return 0;
}