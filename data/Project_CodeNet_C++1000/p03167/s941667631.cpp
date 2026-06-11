#include<bits/stdc++.h>
#define ll long long int
#define db long double
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
#define Nmax 1000005
#define INF 1000000000
#define MOD 1000000007
#define MAXN 1000005
 
using namespace std;

char matrix[1002][1002];
ll dp[1002][1002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests=1,t=1;
    // cin>>tests;
    while(tests--)
    {	
    	ll i,j,h,w;
    	cin>>h>>w;
    	rep(i,1,h)
    	{
    		rep(j,1,w)
    		cin>>matrix[i][j];
    	}
    	dp[h][w]=1;
    	for(i=h;i>=1;i--)
    	{
    		for(j=w;j>=1;j--)
    		{
    			if(matrix[i][j]=='#') continue;
    			dp[i][j]+=dp[i+1][j]+dp[i][j+1];
    			dp[i][j]%=MOD;
    		}
    	}
    	cout<<dp[1][1];


    }
    	return 0;
    
}