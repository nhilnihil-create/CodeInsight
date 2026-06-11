#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N,T;
  cin>>N>>T;
  
  vector<vector<int>> P(N,vector<int>(2));
  for(int i=0;i<N;i++){
    cin>>P[i][0]>>P[i][1];
  }
  
  int mini=10000000;
  
  
  for(int i=0;i<N;i++){
    if(P[i][1]<=T){
      mini=min(mini,P[i][0]);
    }
  }
  
  if(mini==10000000){
    cout<<"TLE"<<endl;
  }
  else{
    cout<<mini<<endl;
  }
}