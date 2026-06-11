#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> x(n);
	rep(i, n) cin >> x[i];
	vector<int> x_ = x;
	sort(x_.begin(), x_.end());
	int res1 = x_[n / 2 - 1];
	int res2 = x_[n / 2];
	for (int i = 0; i < n; ++i) {
		if (x[i] >= res2) printf("%d\n", res1);
		else printf("%d\n", res2);
	}
	return 0;
}
