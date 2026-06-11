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
constexpr auto INF = INT_MAX / 2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n;
	cin >> n;
	map<ll, int> mp;

	ll sum = 0;
	mp[sum]++;

	rep1(i, n) {
		int a;
		cin >> a;
		sum += a;
		mp[sum]++;
	}

	ll ans = 0;
	for (auto x : mp)ans += x.second * ((ll)x.second - 1) / 2;

	cout << ans << endl;

}