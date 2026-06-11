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
	vector<ll> res(k, 0);
	rrep(i, n + 1) res[i % k]++;
	for (int a = 0; a < k; ++a) {
		ll b = (k - a) % k;
		ll c = (k - a) % k;
		if ((b + c) % k != 0) continue;
		ans += res[a] * res[b] * res[c];
	}
	dunk(ans);

	return 0;
}