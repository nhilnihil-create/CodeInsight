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
	int n, k;
	cin >> n >> k;

	ll ans = 0;
	for (int b = 1; b <= n; ++b) {
		ll p = n / b;
		ll g = p * max(0, b - k) + max(0, n % b - k + 1);
		ans += g;
	}
	if (k == 0) ans -= n;

	dunk(ans);
	
	return 0;
}