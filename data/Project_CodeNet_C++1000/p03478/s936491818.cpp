#include <bits/stdc++.h>
using namespace std;

#define println(msg) cout << msg << endl
#define yes_or_no(flag) if (flag) { println("Yes"); } else { println("No"); }

int main() {
  // 入力
  int N, A, B;
  cin >> N >> A >> B;

  // 計算
  int sum = 0;
  for (int i = 1; i <= N; i++) {
    int s = 0;
    for (int n = i; n > 0; n/=10) {
      s += (n % 10);
    }
    if (A <= s && s <= B) {
      sum += i;
    }
  }
  
  // 出力
  println(sum);
}