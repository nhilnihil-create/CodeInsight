#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
  int n;
  cin>>n;
  
  ll *h=new ll[n];
  for(int i=0;i<n;i++)cin>>h[i];
  
  ll *dp=new ll[n];
  dp[0]=0;
  dp[1]=abs(h[1]-h[0]);
  for(int i=2;i<n;i++)
  {
    ll w1=abs(h[i]-h[i-1])+dp[i-1];
    ll w2=abs(h[i]-h[i-2])+dp[i-2];
    dp[i]=min(w1,w2);
  }
  
  cout<<dp[n-1];
  
  
  
}