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
	std::vector<ll> v(n);
	rep(i, n)cin >> v[i];
	ll dp[n];
	dp[0] = 0;
	dp[1] = abs(v[1] - v[0]);

	for (ll i = 2; i < n; ++i) {
		dp[i]=min(dp[i-1]+abs(v[i]-v[i-1]),dp[i-2]+abs(v[i-2]-v[i]));
	}
	cout<<dp[n-1]<<endl;

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
