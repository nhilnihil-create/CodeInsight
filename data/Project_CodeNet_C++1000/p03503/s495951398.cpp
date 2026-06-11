#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,res;
  cin>>n;
  vector<vector<int>> f(n,vector<int>(10)),p(n,vector<int>(11));
  for(auto& v:f)for(int& i:v)cin>>i;
  for(auto& v:p)for(int& i:v)cin>>i;
  for(int i=1;i<(1<<10);++i){
    vector<int> c(n,0);
    for(int j=0;(i>>j)>0;++j){
      if((i>>j)&1)for(int s=0;s<n;++s){
        if(f[s][j])++c[s];
      }
    }
    int sum=0;
    for(int j=0;j<n;++j)sum+=p[j][c[j]];
    if(i>1)res=max(res,sum);
    else res=sum;
  }
  cout<<res;
}