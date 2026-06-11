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
	vector<int> a(3);
	rep(i, 3) cin >> a[i];
	int ans = inf;
	rep(ri, 51) {
		int tmp = ri;
		int cnt = 0;
		rep(i, 3) {
			if (a[i] >= tmp) cnt += a[i] - tmp;
			else cnt += (tmp - a[i]) / 2 + ((tmp - a[i]) % 2 == 0 ? 0 : 2);
		}
		mins(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}
