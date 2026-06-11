#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll k, a, b;
	cin >> k >> a >> b;
	if (k <= a || b <= a + 2) {
		dunk(k + 1);
		return 0;
	}
	k -= a - 1;
	ll ans = a;
	ans += (k / 2ll) * (b - a);
	if (k % 2 >= 1)ans++;
	dunk(ans);
	return 0;
}