#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Y;
  cin >> N >> Y;

  int sum = 0, x = -1, y = -1, t = -1; 
  
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      int z = N - i - j;
      if (z < 0) continue;
      int tmp = 10000 * i + 5000 * j + 1000 * z;
      if (Y == tmp) {
        //cout << i << " " << j << " " << z << endl;
        x = i, y = j, t = z;
      }
    }
  }
  cout << x << " " << y << " " << t << endl;
}