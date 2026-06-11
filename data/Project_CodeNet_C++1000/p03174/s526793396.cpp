#include<bits/stdc++.h>
using namespace std;
int n;
#define ll long long int
const int modn=1e9+7;
int comp[22][22];
int main()
{ cin>>n;
  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
  cin>>comp[i][j];
  
  vector<ll> dp(1<<n);
  dp[0]=1;
  for(int i=0;i<(1<<n);i++)
  { int m=__builtin_popcount(i);
   for(int w=0;w<n;w++)
    {if(comp[m][w]&&(i&(1<<w))==0)
      dp[i|1<<w]= (dp[i|1<<w]+dp[i])%modn;
	}
  }
  	
  cout<<(dp[(1<<n)-1])%modn;
  }
 
