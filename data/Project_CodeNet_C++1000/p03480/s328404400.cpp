#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <stack>
#include <queue>

#define FOR(i, b, e) for(ll i = (ll)(b); i < (ll)(e); ++i)
#define RFOR(i, b, e) for(ll i = (ll)(e-1); i >= 0; --i)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define REPC(x,c) for(const auto& x:(c))
#define VS vector<string>
#define VL vector<long long>
#define VI vector<int>
#define VVI vector<vector<int>>
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define RSORT(x) sort((x).rbegin(),(x).rend())
#define PAIR pair<int,int>
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

using  ll = long long;

using namespace std;

ll conb(ll n, ll r) {
	if (n - r < r) { return conb(n, n - r); }
	ll tmp = 1;
	FOR(i, n - r + 1, n + 1) {
		tmp *= i;
	}
	FOR(i, 1, r + 1) {
		tmp /= i;
	}
	return tmp;
}

ll mod(ll n, ll r) {
	ll q = n % r;
	return (q < 0) ? q + r : q;
}

int main() {
	string s;
	cin >> s;
	ll size = s.size();

	ll min = size;
	REP(i, s.size() - 1) {
		if (s[i] != s[i + 1]) {
			min = std::min(min, std::max(i + 1, size - i - 1));
		}
	}
	cout << min << endl;
}