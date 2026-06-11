#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  int quo=M/N;
  int mod=M%N;
  for(int i=quo;i>=1;i--){
    if(mod%i==0){
      cout << i << endl;
      break;
    }
    mod+=N;
  }
  return 0;
}
