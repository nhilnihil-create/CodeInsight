#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,T;
  cin>>N>>T;
  vector<pair<int,int>> ct(N);
  for (int i=0; i<N; i++){
    cin>>ct.at(i).first>>ct.at(i).second;
  }
  int mini=1001;
  for (int i=0; i<N; i++){
    if (ct.at(i).second<=T){
      if (mini>ct.at(i).first){
        mini=ct.at(i).first;
      }
    }
  }
  if (mini==1001){
    cout<<"TLE"<<endl;
  }else{
    cout<<mini<<endl;
  }
}