#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <bitset>
#include <cmath>
#include <set>
#include <queue>

typedef long long ll;
#define rep(i,s,n)for(ll i = s;i<n;i++)
#define repe(i,s,n)for(ll i = s;i<=n;i++)
#define rep_r(i,s,n)for(ll i = n;i>s;i--)
#define rep_re(i,s,n)for(ll i = n;i>=s;i--)
using namespace std;
static const ll MOD = 1e9 + 7;
static const ll INF = 1e25;
static const ll MAX_N = 100001;

ll match[10] = { 2,5,5,4,5,6,3,7,6 };
string dp[100001];
string INF_S = "-";
ll A[10];

string chmax(string s, string t) {
	if (s == INF_S)return t;
	else if (s.size() < t.size()) return t;
	else if (s.size() > t.size()) return s;
	else if (s.size() == t.size()) {
		return ((s < t) ? t : s);
	}
}

int main() {
	ll n, m; cin >> n >> m;
	rep(i, 0, m) cin >> A[i];
	rep(i, 0, 100001)dp[i] = INF_S;

	dp[0] = "";

	repe(i, 0, n) {
		if (dp[i] == INF_S)continue;

		rep(j, 0, m) {
			dp[i + match[A[j] - 1]] =
				chmax(dp[i + match[A[j] - 1]], dp[i] + (char)('0' + A[j]));
		}
	}
	cout << dp[n] << endl;

	return 0;
}