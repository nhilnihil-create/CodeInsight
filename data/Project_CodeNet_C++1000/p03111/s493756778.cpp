#include<bits/stdc++.h>
using namespace std;

signed main(){

  int n,a,b,c;
  cin>>n>>a>>b>>c;
  vector<int> l(n);
  for(auto& li:l)cin>>li;

  int ans = 1LL<<28;
  auto dfs = [&](auto&& dfs,int aa,int bb,int cc,int i,int mp){
    if(i==n){
      if(aa==0||bb==0||cc==0)return;
      int tmp = abs(aa-a)+abs(bb-b)+abs(cc-c)+mp-30;
      ans = min(ans,tmp);
      return;
    }
    dfs(dfs,aa+l[i],bb,cc,i+1,mp+10);
    dfs(dfs,aa,bb+l[i],cc,i+1,mp+10);
    dfs(dfs,aa,bb,cc+l[i],i+1,mp+10);
    dfs(dfs,aa,bb,cc,i+1,mp);
  };
  dfs(dfs,0,0,0,0,0);
  cout<<(ans)<<endl;

}