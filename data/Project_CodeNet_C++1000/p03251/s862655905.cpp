#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,i;
  cin>>n>>m;
  vector<int> x(n+1),y(m+1);
  cin>>x.at(0)>>y.at(0);
  for(i=1;i<=n;i++) cin>>x.at(i);
  for(i=1;i<=m;i++) cin>>y.at(i);
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  if(x.at(n)<y.at(0)) cout<<"No War"<<endl;
  else cout<<"War"<<endl;
}