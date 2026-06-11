#include <bits/stdc++.h>
using namespace std;

int main() {
  int a = 1, b = 1, c = 1, N, K;
  cin >> N >> K;
  for (int i = 0; i < N; i++){
    a = c * 2;
    b = c + K;
    if (a < b){
      c = a;
    }
    else {
      c = b;
    }
  }
  cout << c << endl;

}
