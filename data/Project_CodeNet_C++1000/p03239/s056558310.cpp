#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,T;
  cin>>N>>T;
  
  vector<pair<int,int>> P(N);
  for(int i=0;i<N;i++){
    cin>>P[i].first>>P[i].second;
  }
  
  int mini=10000000;
  
  
  for(int i=0;i<N;i++){
    if(P[i].second<=T){
      mini=min(mini,P[i].first);
    }
  }
  
  if(mini==10000000){
    cout<<"TLE"<<endl;
  }
  else{
    cout<<mini<<endl;
  }
}