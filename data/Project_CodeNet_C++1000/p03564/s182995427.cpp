#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  
  int var = 1;
  for (int i = 0; i < N; i++){
    if (var * 2 < (var + K)){
      var = var * 2;
    }else{
      var = var + K;
    }
  }
  
  cout << var << endl;
}