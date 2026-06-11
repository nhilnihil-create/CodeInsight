#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> c(N);
  for (int i = 0; i < N; i++) {
    cin >> c[i];  
  }
  
  int a_sum, b_sum;
  a_sum = b_sum = 0;
  
  bool is_a = true;
  
  while (!c.empty()) {
    // 一番大きいのを探す
    int max_arg = -1;
    int max = -1;
    for (int i = 0; i < c.size(); i++) {
      if (max < c[i]) {
        max = c[i];
        max_arg = i;
      }
    }
    // 得点をいれる
    if (is_a) {
      a_sum += max;
    } else {
      b_sum += max;
    }
    // カード除去
    c.erase(c.begin() + max_arg);
    // 攻守交代
    is_a = !is_a;
  }
  
  cout << (a_sum - b_sum) << endl;
}
