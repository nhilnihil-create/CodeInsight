#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  int c = 1;
  for(int i = 0; i < N; i++){
    if(2 * c > c + K){
      c += K;
    }
    if(2 * c <= c + K){
      c = c * 2;
    }
  }
  cout << c;
}