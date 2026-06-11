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

const int N = 100, N2=1e5, M = 1e9+7;

int dp[N2+1];
//array<ll, 3> dp;
//set<string> ans;
//vector<int> low(N, 1), high(N, 1);
ll a[N];

ll n, x;

int main(){
	cin >> n >> x;
	for(int i=0; i<n; ++i)
		cin >> a[i];

	dp[0]=1;
	for(int i=1; i<=n; ++i){
		vector<int> pref_sum(x+1, 0);
		pref_sum[0]=1;
		for(int f=1; f<=x; ++f)
			pref_sum[f]=(pref_sum[f-1]+dp[f])%M;
		for(int j=1; j<=x; ++j){
			if(a[i-1]>=j)
				dp[j]=pref_sum[j];
			else
				dp[j]=(((pref_sum[j]-pref_sum[j-a[i-1]-1])%M)+M)%M;
		}
		// for(int g=1; g<=x; ++g)
		// 	cout << dp[g] << space;
		// cout << ends;
	}


	cout << dp[x] << ends;
}


