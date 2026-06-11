#include<bits/stdc++.h>
using namespace std;
int64_t query(vector<int64_t> &dp,int l,int r,int v,int b,int e){
  if(b>=r||e<=l)
    return 0;
  if(b<=l&&e>=r)
    return dp[v];
  int h=(l+r)/2;
  return max(query(dp,l,h,v*2,b,e),query(dp,h,r,v*2+1,b,e));
}
void update(vector<int64_t> &dp,int l,int r,int v,int i,int64_t x){
  if(i<l||i>=r)
    return;
  if(l==i&&r==i+1){
    dp[v]=x;
    return;
  }
  int h=(l+r)/2;
  update(dp,l,h,v*2,i,x);
  update(dp,h,r,v*2+1,i,x);
  dp[v]=max(dp[v*2],dp[v*2+1]);
  return;
} 
int main(){
  int n;
  cin>>n;
  vector<int> h(n);
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>h.at(i);
    h.at(i)--;
  }
  for(int i=0;i<n;i++)
    cin>>a.at(i);
  vector<int64_t> dp(n*4,0);
  for(int i=0;i<n;i++){
    int64_t q=query(dp,0,n,1,0,h.at(i));
    update(dp,0,n,1,h.at(i),q+a.at(i));
  }
  cout<<dp[1]<<endl;
}