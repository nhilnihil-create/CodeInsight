#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> c(N);
  for (int i = 0; i < N; i++) {
    cin >> c[i];  
  }
  sort(c.begin(), c.end());
  
  int a_sum, b_sum;
  a_sum = b_sum = 0;
  
  bool is_a = true;
  
  while (!c.empty()) {
    int v = c.back(); // 最大値
    c.pop_back(); // カード除去
    
    // 得点をいれる
    if (is_a) {
      a_sum += v;
    } else {
      b_sum += v;
    }
    // 攻守交代
    is_a = !is_a;
  }
  
  cout << (a_sum - b_sum) << endl;
}
