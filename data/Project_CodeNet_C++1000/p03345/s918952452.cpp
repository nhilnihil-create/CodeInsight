#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a, b, c, k;
	cin >> a >> b >> c >> k;
	ll ans = 0;
	if (k % 2 == 0) {
		ans += (a - b);
	}
	else {
		ans += (b - a);
	}
	if (abs(ans) > 1e18) puts("Uufair");
	else dunk(ans);
	return 0;
}