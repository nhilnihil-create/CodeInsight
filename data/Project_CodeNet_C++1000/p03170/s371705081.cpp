#include <bits/stdc++.h>
using namespace std;
long long w[100001],v[100001],dp[1000000];
int main() {
	
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
      long long n,i,j,k,sum=0,count=0,ans=0,x=0,y=0,l,r,m;
      cin>>n>>k;
      long long a[n];
      for(i=0;i<n;i++)
      {
          cin>>a[i];
          dp[a[i]]=1;
      }
      for(i=1;i<=k;i++)
      {
          for(j=0;j<n;j++)
          {
              if(i>=a[j])
              {
                  dp[i]=max(dp[i],(dp[i-a[j]]+1)%2);
              }
          }
      }
      if(dp[k]==1)
      cout<<"First";
      else
      cout<<"Second";
	return 0;
}