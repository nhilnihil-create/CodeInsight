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
	vector<int> v(n), c(n);
	rep(i, n) cin >> v[i];
	rep(i, n) cin >> c[i];
	int ans = 0;
	rep(bit, (1 << n)) {
		int x = 0, y = 0;
		rep(i, n) {
			if (bit & (1 << i)) {
				x += v[i];
				y += c[i];
			}
		}
		maxs(ans, x - y);
	}
	printf("%d\n", ans);
	return 0;
}
