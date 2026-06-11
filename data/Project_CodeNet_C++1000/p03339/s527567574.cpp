#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main(){
  string S;
  int N;
  cin>>N>>S;
  vector<int> V(N);
  for(int i=1;i<N;i++){
    V.at(i)=V.at(i-1);
    if(S.at(i-1)=='W'){
      V.at(i)++;
    }
  }
  vector<int> dp(N);
  dp.at(0)=0;
  int k=0;
  for(int i=1;i<N;i++){
    k=dp.at(i-1);
    if(S.at(i)=='E'){
      k++;
    }
    dp.at(i)=min(k,V.at(i));
  }
  cout<<dp.at(N-1);
}