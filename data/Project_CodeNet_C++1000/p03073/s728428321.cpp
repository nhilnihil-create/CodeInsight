#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 5;
int dp[N][2];
string s;

int solve(int idx, int prv){
	if(idx == s.size())
		return 0;
	int &ans = dp[idx][prv];
	if(~ans)
		return ans;
	if(s[idx] - '0' == prv)
		return ans = solve(idx + 1, !prv) + 1;
	else
		return ans = solve(idx + 1, !prv);
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef ONLINE_JUDGE
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);
#endif
	cin >> s;
	memset(dp, -1, sizeof dp);
	cout << min(solve(0, 0), solve(0, 1));
	return 0;
}
