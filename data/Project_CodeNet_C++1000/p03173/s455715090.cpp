#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define zeroend __builtin_ctz
#define ones __builtin_popcount
#define ends "\n"
#define space ' '
typedef long long ll;
typedef pair<int, int> pii;

/*
void solve(int i, int j, string s){
	if(i==0)
		ans.insert(s2.substr(0, j)+s);
	else if(j==0)
		ans.insert(s1.substr(0, i)+s);
	else if(s1[i-1]==s2[j-1])
		solve(i-1, j-1, s1[i-1]+s);
	else{
		if(dp[i-1][j]<=dp[i][j-1])
			solve(i-1, j, s1[i-1]+s);
		if(dp[i-1][j]>=dp[i][j-1])
			solve(i, j-1, s2[j-1]+s);
	}
}*/


/*
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i];

	for(int i=1; i<n; ++i){
		for(int j=0; j<i; ++j){
			if(a[j]>a[i]&&low[i]<high[j]+1)
				low[i]=high[j]+1;
			else if(a[j]<a[i]&&high[i]<low[j]+1)
				high[i]=low[j]+1;
		}
		ans=max({ans, low[i], high[i]});
	}

	cout << ans << ends;


*/

const int N = 400;

ll dp[N+1][N+1];
ll pref[N+1];
//array<ll, 3> dp;
//set<string> ans;
//vector<int> low(N, 1), high(N, 1);
ll a[N+1];

ll n;

int main(){
	cin >> n;
	pref[0]=0;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		pref[i]=pref[i-1]+a[i];
	}

	for(int i=1; i<=n; ++i)
		dp[i][i]=0;

	for(int i=1; i<n; ++i)
		dp[i][i+1]=a[i]+a[i+1];

	for(int i=2; i<n; ++i){
		for(int j=1; j+i<=n; ++j){
			dp[j][j+i]=1e18;
			for(int k=j; k<i+j; ++k){
				dp[j][j+i]=min(dp[j][j+i], dp[j][k]+dp[k+1][i+j]+pref[i+j]-pref[j-1]);
			}
		}
	}
	cout << dp[1][n] << ends;
}


