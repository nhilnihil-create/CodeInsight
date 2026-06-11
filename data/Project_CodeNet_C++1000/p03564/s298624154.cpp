#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin >> N >> K;
  int j=1;
  for(int i=0;i<N;i++){
    if(j*2<j+K){
      j*=2;
    }
    else{
      j+=K;
    }
  }
  cout << j;
}