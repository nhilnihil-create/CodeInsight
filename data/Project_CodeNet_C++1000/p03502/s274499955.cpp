#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int x = 0;
  int y = N;
  
  for(int i=0; i<8; i++) {
    x += N % 10;
    N /= 10;
  }
  
  if(y % x == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}