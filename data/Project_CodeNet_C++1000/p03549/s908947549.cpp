#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  int ans;
  
  ans=100*(N-M)+M*1900;
  
  for(int i=0;i<M;i++){
    ans *= 2;
  }
  
  cout <<ans <<endl;
  
  return 0;
  
}