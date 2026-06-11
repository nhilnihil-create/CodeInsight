#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,j,ans=0;
  cin>>n;
  vector<vector<int>> a(2,vector<int>(n));
  for(i=0;i<2;i++) for(j=0;j<n;j++) cin>>a.at(i).at(j);
  for(j=1;j<n;j++){
    a.at(0).at(j)+=a.at(0).at(j-1);
    a.at(1).at(n-1-j)+=a.at(1).at(n-j);
  }
  for(j=0;j<n;j++) ans=max(ans,a.at(0).at(j)+a.at(1).at(j));
  cout<<ans<<endl;
}