#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, a=1;
  cin >> N >> K;
  
  for (int i=0; i<N; i++) {
    if (2*a <= (a+K)) {
      a = 2*a;
    }
    else {
      a = a+K;
    }
  }

  cout << a << endl;
}