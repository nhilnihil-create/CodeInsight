#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define FOR(i,a,n) for(int i=a;i<n;i++)

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;
vector<vector<ll>> v;
vector<vector<ll>> dp;

ll solve(int pos, int last) {
	if(pos >= n) return 0;
	if(dp[pos][last] != -1) return dp[pos][last];

	ll res = -LINF;
	FOR(i,0,3) if(i != last) res = max(res, v[pos][i] + solve(pos+1, i));
	return dp[pos][last] = res;
}

int main() { _
	cin >> n;
	v.resize(n, vector<ll>(3));
	dp.resize(n, vector<ll>(4, -1));
	FOR(i,0,n) cin >> v[i][0] >> v[i][1] >> v[i][2];

	cout << solve(0,3) << endl;
	return 0;
}
