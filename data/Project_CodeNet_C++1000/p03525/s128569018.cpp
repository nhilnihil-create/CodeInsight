#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
int n,ans=25;
int main(){
  cin>>n;
  vector<int>d(n+1,0);
  rep(i,n)cin>>d[i];
  sort(d.begin(),d.end());
  rep(i,n+1)if(i&1)d[i]=24-d[i];
  sort(d.begin(),d.end());
  rep(i,n)if(d[i+1]-d[i]<ans)ans=d[i+1]-d[i];
  cout<<min(ans,24-d[n])<<endl;
  return 0;
}
