#include<bits/stdc++.h>
using namespace std;

typedef long long int in;

in dp[3005][3005],cp[3005][3005];

int main() 
{
	in n,l=1000000007,i,j;
	cin>>n;
	
	string s;
	cin>>s;
	
	dp[0][0]=1;
	cp[0][0]=1;
	
	for(i=1;i<3005;++i)
	{
	    cp[0][i]=(cp[0][i]+cp[0][i-1])%l;
	}

	for(i=1;i<n;++i)
	{
	    for(j=0;j<=i;++j)
	    {
	        if(s[i-1]=='>')
	        {
	            if(j==0)
	            dp[i][j]=(cp[i-1][i-1])%l;
	            else
                dp[i][j]=((cp[i-1][i-1]-cp[i-1][j-1])%l+l)%l;
	        }
	        else
	        {
	            if(j==0)
	            dp[i][j]=0;
	            else
	            dp[i][j]=(cp[i-1][j-1])%l;
	        }
	    }
	    
	    for(j=0;j<3005;++j)
	    cp[i][j]=(dp[i][j])%l;
	    
	    for(j=1;j<3005;++j)
	    cp[i][j]=(cp[i][j]+cp[i][j-1])%l;
	    
	}
	
	in ans=0;
	
	for(i=0;i<n;++i)
	ans=(ans+dp[n-1][i])%l;
	
// 	for(i=0;i<n;++i)
// 	{
// 	    for(j=0;j<n;++j)
// 	    cout<<dp[i][j]<<" ";
// 	    cout<<"\n";
// 	}
	
	cout<<ans;
	
	return 0;
}
