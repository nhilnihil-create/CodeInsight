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

int w[33];
vector<ll> a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<int, ll> mp;
	rep(i, n) mp[s[i] - 'a']++;
	ll ans = 0;
	rep(i, n) {
		int d = s[i] - 'a';
		mp[d]--;
		ll tmp = 1;
		rep(j, 26) {
			if (j == d) continue;
			(tmp *= (mp[j] + 1)) %= mod;
		}
		(ans += tmp) %= mod;
	}
	cout << ans << endl;
	return 0;
}
