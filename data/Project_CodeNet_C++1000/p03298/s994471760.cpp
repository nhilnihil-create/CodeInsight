
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,a,b) for (int i = b-1; i >= a; i--)
#define pb push_back


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif

	int n;
	cin>>n;
	string s; cin>>s;
	ll ans = 0;
	ll dp[n+1][n+1];
	f(mask,0,1<<n) {
		string r,t;
		f(i,0,n) if (mask>>i&1) r.pb(s[i]);
		else t.pb(s[i]);
		f(i,0,n+1) f(j,0,n+1) 
			dp[i][j] = 0;
		int a = r.size(), b = s.size();
		dp[0][0] = 1;
		f(i,0,n) f(j,0,a+1) if (dp[i][j]) {
			int k = i-j;
			char cur = s[2*n-1-i];
			if (j<a&&cur==r[j]) dp[i+1][j+1] += dp[i][j];
			if (k<b&&cur==t[k]) dp[i+1][j] += dp[i][j];
		}	
		ans += dp[n][a];
	}	
	cout << ans << endl;
	

#ifdef LOCAL
	cout << setprecision(12) << (long double)(clock()-start) / CLOCKS_PER_SEC << endl;
#endif
	
	return 0;
}

