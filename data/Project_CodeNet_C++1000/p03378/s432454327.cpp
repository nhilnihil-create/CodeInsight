#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, M, X;
  cin>>N>>M>>X;
  vector<int> bomb(M, 0);
  for(int i=0; i<M; i++){
    cin>>bomb.at(i);
  }
  int cost=0;
  for(int i=0; i<M; i++){
    if(bomb.at(i)<X){
      cost++;
    }
    else{
      break;
    }
  }
  if(cost<=M-cost){
    cout<<cost<<endl;
  }
  else{
    cout<<M-cost<<endl;
  }
}