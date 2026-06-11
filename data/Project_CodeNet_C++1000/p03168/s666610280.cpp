#include<bits/stdc++.h>

using namespace std ;
#define ll long long int
#define pb push_back
#define mod 1000000007;
#define db long double

int n;

int main()
{

   #ifdef patil
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

   cin>>n;
   db p[n];
   for(int i=0;i<n;i++)cin>>p[i];
   	
   	db dp[n+1][n+1];
    for(int i=0;i<=n;i++)
    	dp[0][i]=0;
    dp[0][0]=1;

    for(int i=1;i<=n;i++)
    {
    	for(int j=0;j<=i;j++)
    	{
    		if(j==0)dp[i][j]=(1-p[i-1])*dp[i-1][0];
            else if(i==j)dp[i][j]=p[i-1]*dp[i-1][j-1];
    		else dp[i][j] = p[i-1]*dp[i-1][j-1] + (1-p[i-1])*dp[i-1][j];
    	}
    }
    db ans=0;
    int index = n/2;
    index++;
    for(int i=index;i<=n;i++)
    	ans +=dp[n][i]; 
    cout<<setprecision(15)<<ans<<endl;


	return 0;

}