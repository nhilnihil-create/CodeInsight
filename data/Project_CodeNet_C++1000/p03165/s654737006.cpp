#include <bits/stdc++.h>
#ifdef LOCAL
#include <pprint.hpp>
#endif
#define endl "\n";
#define pb push_back
#define md 1000000007
#define ll long long int
#define all(v) v.begin(),v.end()
ll power(ll a,ll b){ll z=1;while(b){if(b&1){z*=a;z%=md;}a*=a;a%=md;b/=2;}return z%md;}
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	//You need to change array size!
	#ifndef LOCAL
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	#endif 
	
	string s,t;
	cin>>s>>t;
	ll n=s.length(),m=t.length();
	vector<vector<ll>> dp;
	dp.assign(n+1,vector<ll>(m+1,0));
	vector<vector<char>> dir(n+1,vector<char>(m+1,'0'));

	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(s[i-1]==t[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
				dir[i][j]='D';
			}
			else if(dp[i-1][j]>dp[i][j-1]){
				dp[i][j]=dp[i-1][j];
				dir[i][j]='U';
			}
			else{
				dp[i][j]=dp[i][j-1];
				dir[i][j]='R';
			}

	// for(auto x:dir)
		// cout<<x<<endl;
	string ans;
	int i=n,j=m;
	while(i>0 && j>0){
		if(dir[i][j]=='D'){
			ans+=s[i-1];
			i--;	j--;
		}
		else if(dir[i][j]=='R')
			--j;
		else if(dir[i][j]=='U')
			--i;
	}
	reverse(all(ans));
	cout<<ans;
	return 0;	
}