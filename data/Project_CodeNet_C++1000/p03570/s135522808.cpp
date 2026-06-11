#include <bits/stdc++.h>

#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define reset(a, v) memset ((a), v, sizeof (a))

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ii> vii;

const int N = 200005;
const int INF = (int)1e+9;

int n;
string S;
int dat[N];
map <int, int> dp;

int get (int x) {
	if (dp.find(x) == dp.end()) return INF;
	return dp[x];
}

int Solve () {
	int res = 0;
	for (int i = 0; i < n; ++i) {
		int dp_now = INF;
		res ^= dat[i];
		dp_now = min (dp_now, 1 + get (res));
		for (int i = 0; i < 26; ++i) {
			dp_now = min (dp_now, 1 + get (res ^ (1 << i)));
		}

		if (dp.find(res) == dp.end()) dp[res] = dp_now;
		else dp[res] = min (dp[res], dp_now);

		if (i == n - 1) return dp_now;
	}
}

int main () {
	cin >> S;
	n = S.length();
	dp[0] = 0;
 	for (int i = 0; i < n; ++i) {
		dat[i] = 1 << (S[i] - 'a');
		//printf ("%d\n", dat[i]);
	}

	printf ("%d\n", Solve ());
	return 0;
}