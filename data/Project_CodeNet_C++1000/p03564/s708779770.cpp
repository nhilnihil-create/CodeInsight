#include <bits/stdc++.h>
using namespace std;


int main() {
  int N, K;
  cin >> N >> K;
  
  int board = 1;
  for (int i=0; i<N; i++) {
    if (board <= K) board *= 2;
    else board += K;
  }
  
  cout << board << endl;

  return 0;
}
