#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,i,ans=0;
  cin>>n>>m;
  vector<int> x(m),d(m-1);
  for(i=0;i<m;i++) cin>>x.at(i);
  sort(x.begin(),x.end());
  for(i=0;i<m-1;i++) d.at(i)=x.at(i+1)-x.at(i);
  sort(d.begin(),d.end());
  for(i=0;i<m-n;i++) ans+=d.at(i);
  cout<<ans<<endl;
}