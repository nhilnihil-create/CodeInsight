#include <vector>
#include <iostream>

using namespace std;
#define maxn 200001
struct _ { ios_base::Init i; _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

long long n, ans;
vector<long long> h(maxn, 0);
vector<long long> a(maxn, 0);
vector<long long> dp(maxn, 0);
vector<long long> BIT(maxn, 0);

void update(long long ind, long long val) {
	while (ind < maxn) {
		BIT[ind] = max(BIT[ind], val);
		ind += (ind & -ind);
	}
}

long long query(long long ind) {
	long long res = 0;
	while (ind > 0) {
		res = max(res, BIT[ind]);
		ind -= (ind & -ind);
	}
	return res;
}

int main() {

	cin >> n;
	for (long long i = 1; i <= n; i++) cin >> h[i];
	for (long long i = 1; i <= n; i++) cin >> a[i];

	for (long long i = 1; i <= n; i++) {
		long long val = query(h[i]);
		dp[i] = a[i] + val;
		update(h[i], dp[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}