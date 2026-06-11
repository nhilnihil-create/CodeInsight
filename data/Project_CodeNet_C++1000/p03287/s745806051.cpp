#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n, m;
	cin >> n >> m;
	vi a(n);
	rep(i, n)cin >> a[i];
	vi sum(n + 1);
	rep(i, n)sum[i + 1] = (sum[i] + a[i]) % m;
	map<int, int> mp;
	rep(i, n + 1)mp[sum[i]]++;

	ll ans = 0;
	for (auto x : mp)ans += (ll)x.second * (x.second - 1) / 2;

	cout << ans << endl;

}