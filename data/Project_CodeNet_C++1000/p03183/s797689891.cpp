#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct block{
  int w,s,v;
  bool operator<(const block &b) const{
  	return w+s<b.w+b.s;
  }
};

int main(){
  int n,maxwt=0;
  cin>>n;
  vector<block> v(n);
  for(int i=0;i<n;i++)
  {
  	cin>>v[i].w>>v[i].s>>v[i].v;
    maxwt+=v[i].w;
  }
  sort(v.begin(),v.end());
  vector<long> dp(maxwt+5);
  for(int i=0;i<n;i++)
  {
	for(int j=min(v[i].s,maxwt-v[i].w);j>=0;j--)
      dp[j+v[i].w]=max(dp[j+v[i].w],dp[j]+v[i].v);
  }
  long ans=-1;
  for(int j=maxwt;j>=0;j--)
    ans=max(ans,dp[j]);
  cout<<ans;
  
}