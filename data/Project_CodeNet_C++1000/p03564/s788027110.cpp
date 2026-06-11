#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, a=1;
  cin >> N >> K;
  for (int i = 0; i < N; i++){
    if (a > K){
    a += K;
    continue;
    }
    
    a *= 2;
  }
  cout << a << endl;
}