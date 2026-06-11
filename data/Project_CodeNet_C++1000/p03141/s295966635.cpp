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
	int n;
	cin >> n;
	vector<ll> res(n);
	ll sol = 0;
	rep(i, n) {
		int a, b; cin >> a >> b;
		sol += b;
		res[i] = a + b;
	}
	sort(rall(res));
	ll ans = 0;
	rep(i, n) {
		if (i % 2 == 0) {
			ans += res[i];
		}
	}
	ans -= sol;
	dunk(ans);
	return 0;
}
