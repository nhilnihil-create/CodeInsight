#include <bits/stdc++.h>
using namespace std;

#define println(msg) cout << msg << endl
#define yes_or_no(flag) if (flag) { println("Yes"); } else { println("No"); }

int main() {
  // 入力
  int A, B;
  cin >> A >> B;
  
  // 計算
  int count = 0;
  for (int i = A; i <= B; i++) {
    string s = to_string(i);
    int x = s.size() / 2;
    bool all = true;
    for (int j = 0; j < x; j++) {
      if (s[j] != s[s.size() - j - 1]) {
        all = false;
      }
    }
    if (all) {
      count++;
    }
  }
  
  // 出力
  println(count);
}
