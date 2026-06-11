#include <bits/stdc++.h>
using namespace std;

struct block{int w,s;long long v;};
bool cmp(block a,block b){
  return a.w+a.s<b.w+b.s;
}
long long ans,dp[20001];

template<typename T>
void chmax(T &a,T b){
  if(a<b)a=b;
}

int main(){
  int n;cin>>n;
  vector<block> a(n);
  for(int i=0;i<n;i++){
    int w,s,v;cin>>w>>s>>v;
    a[i]={w,s,v};
  }
  sort(a.begin(),a.end(),cmp);
  for(int i=0;i<n;i++)
    for(int j=a[i].s;j>=0;j--)chmax(dp[j+a[i].w],dp[j]+a[i].v);
  for(int i=0;i<20001;i++)chmax(ans,dp[i]);
  cout<<ans<<endl;
}
