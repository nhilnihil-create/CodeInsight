#include <bits/stdc++.h>
#define ll long long int 
#define endl '\n'
#define INF 1000000000
#define MOD 1000000007
#define MAX 100000000 
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll h,w;
    cin>>h>>w;
    string s[h];
    for(int i=0;i<h;i++)
    {
    	cin>>s[i];
    	//cout<<s[i]<<endl;
    }
    ll dp[h][w];
    for(int i=0;i<h;i++)
    {
    	for(int j=0;j<w;j++)
    	{
    		if(s[i][j]=='#')
    		{
    			dp[i][j]=0;
    			continue;
    		}
    		if(i==0&&j==0)
    		{
    			dp[i][j]=1;
    			continue;
    		}
    		if(i==0)
    		{
    			dp[i][j]=dp[i][j-1];
    		}
    		else
    		if(j==0)
    		{
    			dp[i][j]=dp[i-1][j];
    		}
    		else
    		{
    			dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
    		}
    	}
    }
    cout<<dp[h-1][w-1];
}