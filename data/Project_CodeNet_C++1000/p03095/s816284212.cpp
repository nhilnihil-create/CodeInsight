#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n;
	string s;
	cin >> n >> s;
	map<char, int> mp;
	rep(i, n)mp[s[i]]++;

	ll ans = 1;
	for (auto x : mp){ans *= x.second + 1;ans %= MOD;}

	cout << ans - 1 << endl;

}