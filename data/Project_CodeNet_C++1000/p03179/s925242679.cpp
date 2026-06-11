#include<bits/stdc++.h>
#define int long long int  //comment for large arrays
#define pll pair<int,int>
#define dbl long double
#define ff first
#define ss second
#define endl "\n"
#define mod 1000000007
#define eps 0.00000001
#define INF 10000000000000001
#define all(x) (x).begin(),(x).end()
#define LB(v,x) (lower_bound(all(v),x) - v.begin()) 
#define UB(v,x) (upper_bound(all(v),x) - v.begin())
#define size(x) (int)(x).size()
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define popb() pop_back()
#define popf() pop_front()
#define mp(x,y) make_pair((x),(y))
#define vec(dt) vector<dt>
#define vv(dt) vector<vector<dt>>
#define fastio(x) ios_base::sync_with_stdio(x); cin.tie(NULL)
#define init(v,s) memset(v,s,sizeof(v)) 
#define bug(x) cerr<<"LINE: "<<__LINE__<<" || click to see test details "<<#x<<" = "<<x<<endl
#define loop(i,s,n) for(int i=s;i<n;i++)
#define print(v) for(auto it:v) cout<<it<<" "; cout<<endl 
using namespace std;


signed main()
{
	fastio(0);
	int n;
	string s;
	cin>>n;
	cin>>s;
	s = '*' + s;
	int dp[n+1],prefix[n+1];  
	init(dp,0);
	init(prefix,0);
	
	dp[1] = 1;
	loop(j,1,n+1) prefix[j] = (prefix[j-1] + dp[j])%mod; 
	loop(i,2,n+1)
	{
		loop(j,1,i+1)
			if(s[i-1]=='>')	dp[j] = (prefix[n] - prefix[j-1] + mod)%mod;
			else dp[j] = prefix[j-1]%mod;
		loop(j,1,n+1) prefix[j] = (prefix[j-1] + dp[j])%mod; 		
	}
	cout<<prefix[n]<<endl;
	return 0;		
}
