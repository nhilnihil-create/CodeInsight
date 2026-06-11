#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n,m;cin>>n>>m;
  vector<int> x(m);
  for(int i=0; i<m; ++i) cin>>x[i];
  sort(x.begin(),x.end());
  vector<int> dis(m-1);
  for(int i=1; i<m; ++i) dis[i-1]=x[i]-x[i-1];
  sort(dis.rbegin(),dis.rend());
  int res=x.back()-x[0];
  for(int i=0; i<min(m-1,n-1); ++i) res-=dis[i];
  cout<<res<<endl;
  return 0;
}