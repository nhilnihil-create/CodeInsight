#include <bits/stdc++.h>
using namespace std;

#define println(msg) cout << msg << endl
#define yes_or_no(flag) if (flag) { println("Yes"); } else { println("No"); }

int xxx(int x) {
  int sum = 0;
  while (x > 0) {
    sum += (x % 10);
    x /= 10;
  }
  return sum;
}

int main() {
  // 入力
  int N;
  cin >> N;
  
  // 計算
  int min = INT_MAX;
  for (int a = 1; a < N; a++) {
    int b = N - a;
    int t = xxx(a) + xxx(b);
    if (t < min) {
      min = t;
    }
  }
  
  // 出力
  println(min);
}