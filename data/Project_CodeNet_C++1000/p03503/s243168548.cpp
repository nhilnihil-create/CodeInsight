#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,j,k,ans=-1e9-1;
  cin>>n;
  vector<vector<int>> f(n,vector<int>(10)),p(n,vector<int>(11));
  for(i=0;i<n;i++) for(j=0;j<10;j++) cin>>f.at(i).at(j);
  for(i=0;i<n;i++) for(j=0;j<11;j++) cin>>p.at(i).at(j);
  for(i=1;i<(1<<10);i++){
    bitset<10> b(i);
    vector<int> c(n);
    int x=0;
    for(j=0;j<10;j++) if(b.test(j)) for(k=0;k<n;k++) c.at(k)+=f.at(k).at(j);
    for(k=0;k<n;k++) x+=p.at(k).at(c.at(k));
    ans=max(ans,x);
  }
  cout<<ans<<endl;
}