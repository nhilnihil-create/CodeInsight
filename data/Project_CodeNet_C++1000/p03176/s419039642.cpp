#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int h[n],a[n];
  for(int i=0;i<n;i++)
    cin>>h[i];
  for(int i=0;i<n;i++)
    cin>>a[i];
  
  int base=1;
  while(base<=n)
  {
    base*=2;
  }
  long tree[2*base]={0};
  long dp[n+1]={0},ans=0;
  for(int i=0;i<n;i++)
  {
    long cnt=0;
    int x=h[i]+base;
    while(x>1)
    {
      if(x%2==1)
        cnt=max(cnt,tree[x-1]);
      x/=2;
    }
    dp[h[i]]=cnt+a[i];
    for(int j=base+h[i];j>=1;j/=2)
      tree[j]=max(tree[j],dp[h[i]]);
    
    //for(int j=0;j<h[i];j++)
      //dp[h[i]]=max(dp[h[i]],dp[j]+a[i]);
    ans=max(ans,dp[h[i]]);
  }
  cout<<ans;

}