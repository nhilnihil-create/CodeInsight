#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,i,ans=0;
  vector<pair<int,int>> v;
  for(i=0;i<5;i++){
    cin>>a;
    b=(a+9)/10*10;
    v.push_back(make_pair(b-a,b));
  }
  sort(v.begin(),v.end());
  for(i=0;i<5;i++){
    ans+=v.at(i).second;
    if(i==4) ans-=v.at(i).first;
  }
  cout<<ans<<endl;
}