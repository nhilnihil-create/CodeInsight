#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M,a,b;
  vector<pair<int,int>>vec;
  cin>>N>>M;
  for(int i=0;i<M;i++){
    cin>>a>>b;
    vec.emplace_back(b,a);
  }
  int temp=-1;
  int cnt=0;
  sort(vec.begin(),vec.end());
  for(auto itr=vec.begin();itr !=vec.end();itr++){
    //cout<<itr->second<<" "<<itr->first<<"temp"<<temp<<endl;
    if((itr->second)<=temp && temp<(itr->first)) continue;
    //cout<<itr->second<<"*"<<itr->first<<endl;
    //cout<<(itr->first)-1<<endl;
    cnt++;
    temp=(itr->first)-1;
  }

  cout<<cnt<<endl;
 
  return 0;
}
 

