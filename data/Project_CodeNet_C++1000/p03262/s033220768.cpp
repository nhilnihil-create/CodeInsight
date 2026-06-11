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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, X;
	cin >> n >> X;
	vector<int> x(n);
	rep(i, n) cin >> x[i];
	x.push_back(X);
	sort(all(x));
	int ans = x[1] - x[0];
	for (int i = 2; i <= n; ++i) {
		ans = gcd(ans, x[i] - x[i - 1]);
	}
	printf("%d\n", ans);
	return 0;
}
