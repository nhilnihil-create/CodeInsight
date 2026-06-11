#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin>>N;
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  int cnt =0;
bool x=true;
  rep(i,N){
x=true;
    for(int j=i+1;j<N;j++){
      if(vec.at(i)==vec.at(j)){
        x=false;
      }
    }
if(x){
cnt+=1;}
  }
  cout<<cnt;}
  
