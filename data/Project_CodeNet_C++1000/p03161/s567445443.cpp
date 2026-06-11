#include<bits/stdc++.h> 
using namespace std; 
#define deb(x) cout <<"\n"<< (#x) << " = " << (x) << "\n"
const long long  INF = 1e18;
const long long mod=1e9+7 ;
void inputoutput()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	    
}

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> ar(n);
	for(int i=0 ; i<n ; ++i)
		cin>>ar[i];

	int dp[n];
	// dp[i][j] => if I start from this pos till ith positon the minimum i need 
	// to spend if i can stay only k minutes in a bus
			
	dp[n-1]=0;

	for(int i=n-2 ; i>=0 ; --i)
	{
		dp[i]=INT_MAX ;
		for(int m=0 , j=i+1 ; m<k && j<n ; ++m , ++j)
		{
			dp[i]=min(dp[j]+abs(ar[i]-ar[j]) , dp[i] ) ;	
		}
	}

	cout<<dp[0];
	cout<<"\n";


}
int32_t main()
{ 
	inputoutput() ;
	solve();


	return 0;
}
