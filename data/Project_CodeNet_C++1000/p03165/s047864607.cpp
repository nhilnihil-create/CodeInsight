#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define mod 1000000007
#define dbg if(debug)
#define size(x) (int)(x).size()
using namespace std;
typedef pair<int,int> pii;
#ifdef OMNI
	const bool debug = 1;
#else
	const bool debug = 0;
#endif

//---------------------- PROVE, THEN WRITE ----------------------//


int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);cout.tie(NULL);
	string s,t;
	cin>>s>>t;
	int n=s.length(),m=t.length();
	vector<vector<int> > dp(n+1,vector<int> (m+1));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(s[i-1]==t[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	int y = m;
	int x = n;
	string ans="";
	while(x>0 && y>0){
		if(s[x-1]==t[y-1]){
			ans += t[y-1];
			y--;
			x--;
		}
		else if(dp[x-1][y] > dp[x][y-1]){
			x--;
		}
		else
			y--;
	}
	reverse(all(ans));
	cout<<ans;
	// cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
	return 0;
}
	