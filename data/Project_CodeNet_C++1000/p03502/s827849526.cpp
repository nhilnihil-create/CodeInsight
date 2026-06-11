#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  // ここにプログラムを追記
  int sum = 0, X = N;
  while(X >= 1) {
    sum += X%10;
    X /= 10;
  }
  if(N%sum == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}