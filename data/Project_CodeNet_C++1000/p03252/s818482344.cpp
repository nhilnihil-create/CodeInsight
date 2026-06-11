#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
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

	string s, t;
	cin >> s >> t;

	map<char, char> mp, pm;
	rep(i, s.size()) {
		mp[s[i]] = t[i];
		pm[t[i]] = s[i];
	}
	bool ok = true;
	rep(i, s.size())if (mp[s[i]] != t[i])ok = false;
	rep(i, t.size())if (pm[t[i]] != s[i])ok = false;
	cout << (ok ? "Yes" : "No") << endl;

}