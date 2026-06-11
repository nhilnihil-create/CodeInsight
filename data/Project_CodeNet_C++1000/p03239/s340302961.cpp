#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,T;cin>>N>>T;
  vector<pair<int,int>> A;
  for(int i=0;i<N;i++){
    int c,t;cin>>c>>t;
    A.push_back(make_pair(c,t));
  }
  sort(A.begin(),A.end());
  int ans=0;
  for(int i=0;i<N;i++){
    if(A.at(i).second<=T){
      ans=A.at(i).first;
      break;
    }
  }
  if(ans==0) cout<<"TLE"<<endl;
  else cout<<ans<<endl;
}
    
