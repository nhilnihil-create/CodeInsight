#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
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
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	vector<ll> res(n);
	ll sum = 0;
	rep(i, n) {
		sum += b[i];
		res[i] = a[i] + b[i];
	}
	sort(rall(res));
	ll ans = 0;
	rep(i, n) {
		if (i % 2 == 0) ans += res[i];
	}
	cout << ans - sum << endl;
	return 0;
}
