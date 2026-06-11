#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define size 200010
ll dp[4*size];
ll query(int s, int e, int qs, int qe, int idx)
{
  if(qs>e||qe<s)
    return 0;
  if(qs<=s&&qe>=e)
    return dp[idx];
  int mid=(s+e)/2;
  ll  a = query(s,mid,qs,qe,2*idx);
  ll  b = query(mid+1,e,qs,qe,2*idx+1);
  return max(a,b);
  
}
void update(int s,int e ,ll value ,int height,int idx)
{
    if(s>height||e<height) return;
  if(s==e){
    dp[idx]=value;
   // cout<<dp[idx]<<" "<<idx<<" ";
    return ;
  }
  int mid=(s+e)/2;
     update(s,mid,value,height,2*idx);
    update(mid+1,e,value,height,2*idx+1);
 
  dp[idx]=max(dp[2*idx],dp[2*idx+1]);
 // return ;
  
}
int main()
{
  int n;
  cin>>n;
  int i;
  vector<int> height(n,0),beauty(n,0);
  for(i=0;i<n;i++) cin>>height[i];
  for(i=0;i<n;i++) cin>>beauty[i];
  memset(dp,0,sizeof(dp));
  ll x=INT_MIN,a=0;
  for(i=0;i<n;i++)
  {
      a=query(0,n,0,height[i]-1,1);
     //x = max(x,a+beauty[i]);
    // cout<<a<<endl;
    update(0,n,beauty[i]+a, height[i],1);
  }
  //for(i=1;i<4*n;i++)
  //cout<<dp[i]<<" ";
  cout<<dp[1]<<endl;
}