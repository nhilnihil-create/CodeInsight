#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	ll n,ans=INF;
	cin >> n;
	vector<ll>arr(n);
	rep(i, n)cin >> arr[i];
	rep(i, n-1) {
		ans = min(ans,gcd(arr[i], arr[i + 1]));
	}
	cout << ans << endl;
	return 0;
}

