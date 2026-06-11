#include<bits/stdc++.h>
using namespace std;
//ai*log(ai);
//solve dynamic programming problems
//dp with bitmasks
vector< vector<int> > p;
int answer=0;
void permute(int s[],int l,int r,int n)
{
	if(l==r)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=p[i][s[i]];
		}
		answer=max(answer,ans);
	}
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(s[i],s[l]);
		permute(s,l+1,r,n);
		swap(s[i],s[l]);	
		}
	}
}
const int MOD=1e9+7;
int countbit(int mask)
{ int count=0;
	while(mask)
	{
		if(mask%2)count++;
		mask=mask/2;
	}
	return count;
}
signed main()
{
  int n;cin>>n;
  int a[n+1][n+1];
  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
  cin>>a[i][j];
  int powe[n]={0};
  powe[0]=1;
  //cout<<"OK"<<endl;
  for(int i=1;i<=n;i++)
  {
  	powe[i]=powe[i-1]*2;
  }
 int dp[powe[n]+1]={0};
 dp[0]=1;
 for(int mask=0;mask<powe[n];mask++)
 { 
 int k=countbit(mask);
 	for(int j=0;j<n;j++)
 	{
 	 if(!(mask&(1<<j)))
	  {
	  	if(a[k][j])
	   dp[mask|(1<<j)]+=dp[mask];
	   dp[mask|(1<<j)]%=MOD;  	
	  }	
	}
 }
 cout<<dp[powe[n]-1]<<endl;
}