#include <bits/stdc++.h>
using namespace std;

bool isResolvable(int N, int Y) {
  if (10000 * N < Y) return false;
  if (1000 * N > Y) return false;
  return true;
}

int main(){
  int N, Y;
  cin >> N >> Y;
  
  int x, y, z;
  x = y = z = -1;
  bool found = false;
  
  if (isResolvable(N , Y)) {
    for (int i = 0; i <= N; ++i) {
      for (int j = 0; j <= N - i; ++j) {
        int k = N - i - j;
        if (k < 0) continue;

        int amount = 10000 * i + 5000 * j + 1000 * k;
        if (amount == Y) {
          found = true;
          x = i; y = j; z = k;
          break;
        }
      }
      if (found) break;
    }
  }    
  cout << x << " " << y << " " << z << endl;
}