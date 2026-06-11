#include <bits/stdc++.h>
using namespace std;

//const long double PIL = 3.141592653589793238462643383279502884L;
//const double PI = 3.14159265358979323846;

#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define what_is(x) cerr << #x << " is " << x << endl;

using ll = long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vll = vector<long long>;
using vii = vector<pair<int,int>>;

const int MOD = 1e9 + 7;
ll dp[100005][4];

int main() {
	//~ ios::sync_with_stdio(0);
	//~ cin.tie(0);
	string s;
	cin >> s;
	int n = s.length();
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		char c = s[i-1];
		for (int j = 0; j <= 3; j++)
			dp[i][j] = dp[i-1][j] * (c == '?'? 3 : 1);

		if (c == 'A' || c == '?') dp[i][1] += dp[i-1][0];
		if (c == 'B' || c == '?') dp[i][2] += dp[i-1][1];
		if (c == 'C' || c == '?') dp[i][3] += dp[i-1][2];

		for (int j = 0; j <= 3; j++) dp[i][j] %= MOD;
	}
	printf("%lld\n", dp[n][3]);
}
