typedef long long int ll;
typedef unsigned long long int ull;
#define fast  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define sec second
#define fir first
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repe(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define entire(a) (a).begin(),(a).end()
#define pb push_back
#define pii pair<int,int>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;

void solve() {
	ll n;
	cin >> n;
	ll vac[n][3];
	rep(i, n)rep(j, 3)cin >> vac[i][j];
	ll dp[n][3];
	rep(i, 3)
	dp[0][i] = vac[0][i];

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			dp[i][j] = vac[i][j] + max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
			// cout<<dp[i][j]<<" ";
		}
		// cout<<endl;
	}
	cout << max(dp[n - 1][0] , max(dp[n - 1][1] , dp[n - 1][2])) << endl;
}

int main() {

	fast
	int T = 1;
	// cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}
