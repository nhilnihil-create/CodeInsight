#include<bits/stdc++.h>
using namespace std;
int main(){
  int z,i,ans=0;
  cin>>z;
  vector<int> y(z);
  for(i=0;i<z;i++) cin>>y.at(i);
  sort(y.begin(),y.end());
  reverse(y.begin(),y.end());
  for(i=0;i<z;i++){
    if(i%2==0) ans+=y.at(i);
    else ans-=y.at(i);
  }
  cout<<ans<<endl;
}