#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K, x = 1;
  cin >> N >> K;
  for (int i = 0; i < N; i++){
    if (K <= x){
      x += K;
    }
    else {
      x += x;
    }
  }
  cout << x << endl;
}