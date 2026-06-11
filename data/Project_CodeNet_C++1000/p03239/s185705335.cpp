#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,T;
  cin>>N>>T;
  vector<pair<int,int>> P(N);
  for(int i=0;i<N;i++){
    cin>>P.at(i).first>>P.at(i).second;
  }
  int ans=1000;
  bool a=false;
  for(int i=0;i<N;i++){
    if(P.at(i).second<=T){
      ans=min(ans,P.at(i).first);
      a=true;
    }
  }
  if(a){
    cout<<ans<<endl;
  }
  else{
    cout<<"TLE"<<endl;
  }
}
