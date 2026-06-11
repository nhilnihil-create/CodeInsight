#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,a,i,j,k,ans=0;
  cin>>h>>w;
  vector<vector<int>> c(10,vector<int>(10));
  for(i=0;i<10;i++) for(j=0;j<10;j++) cin>>c.at(i).at(j);
  for(k=0;k<10;k++) for(i=0;i<10;i++) for(j=0;j<10;j++) c.at(i).at(j)=min(c.at(i).at(j),c.at(i).at(k)+c.at(k).at(j));
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      cin>>a;
      if(a!=-1) ans+=c.at(a).at(1);
    }
  }
  cout<<ans<<endl;
}