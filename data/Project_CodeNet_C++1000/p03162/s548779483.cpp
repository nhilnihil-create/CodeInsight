#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> 
//using namespace boost::multiprecision; 

using namespace std;

//#Rohitpratap311
//#Keep Calm And Stay Happy

typedef long long ll;
typedef long double ld;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    ll arr[n][3];
    for(ll i=0;i<n;i++)
    {
    	cin>>arr[i][0]>>arr[i][1]>>arr[i][2];	
    }
    ll dp[n][3];
    for(ll i=0;i<n;i++)
    {
    	for(ll j=0;j<3;j++)
    	{
    		if(i==0) { dp[i][j]=arr[i][j]; }
    		else
    		{
    			if(j==0) { dp[i][j]=arr[i][j]+max(dp[i-1][1],dp[i-1][2]); }
    			if(j==1) { dp[i][j]=arr[i][j]+max(dp[i-1][0],dp[i-1][2]); }
    			if(j==2) { dp[i][j]=arr[i][j]+max(dp[i-1][0],dp[i-1][1]); }
    		}
    	}
    }
 	cout<<max(max(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
	return 0;
}