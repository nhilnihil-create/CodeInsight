#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int K;
  cin >> N >> K;
  
  int j = 1;
  
  for(int i = 0; i < N; i++) {
    int a = j * 2;
    int b = j + K;
    if(a > b) {
      j += K;
    }
    else {
      j *= 2;
    }
  }
  
  cout << j << endl;
}
