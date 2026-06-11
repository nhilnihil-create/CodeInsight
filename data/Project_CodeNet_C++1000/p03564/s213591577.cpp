#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, a = 1;
  cin >> N >> K;
  for(; N > 0; N--) {
    if(a > K) {
      a += K;
    }
    else {
      a *= 2;
    }
  }
  
  cout << a << endl;
}