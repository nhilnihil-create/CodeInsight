#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, Y;
  cin >> N >> Y;
  
  // x + y + z = N
  // 10000x + 5000y + 1000z = Y
  int a = -1, b = -1, c = -1;
  for (int x = 0; x <= N; x++) {
    for (int y = 0; x + y <= N; y++) {
      	int z = N - x - y;
        if (Y == 10000*x + 5000*y + 1000*z) {
          a = x; b = y; c = z;
        }
    }
  }
  cout << a << " " << b << " " << c << endl;
}
