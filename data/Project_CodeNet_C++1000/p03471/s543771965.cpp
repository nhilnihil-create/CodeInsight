#include <bits/stdc++.h>
using namespace std;

#define println(msg) cout << msg << endl

int main() {
  // 入力
  int N, Y;
  cin >> N >> Y;
  
  // 計算
  int r10000 = -1;
  int r5000 = -1;
  int r1000 = -1;
  for (int a = 0; a <= N; a++) {
    for (int b = 0; (b + a) <= N; b++) {
      int c = N - a - b;
      int yen = 10000*a + 5000*b + 1000*c;
      if (yen == Y) {
        r10000 = a;
        r5000 = b;
        r1000= c;
      }
    }
  }
  // 出力
  cout << r10000 << " " << r5000 << " " << r1000 << endl;
}