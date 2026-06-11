#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, K, X = 1;
  cin >> N >> K;
  
  rep(i,N){
    if(X < K){
      X *= 2;
    }
    else{
      X += K;
    }
  }
    
    cout << X << endl;
}