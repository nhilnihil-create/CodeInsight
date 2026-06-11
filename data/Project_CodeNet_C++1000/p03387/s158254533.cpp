#include<bits/stdc++.h>
using namespace std;
int main(){
  int i,ans;
  vector<int> a(3);
  for(i=0;i<3;i++) cin>>a.at(i);
  sort(a.begin(),a.end());
  ans=(a.at(1)-a.at(0))/2;
  a.at(0)+=2*ans;
  if(a.at(0)<a.at(1)){
    a.at(0)++;
    a.at(2)++;
    ans++;
  }
  ans+=a.at(2)-a.at(1);
  cout<<ans<<endl;
}