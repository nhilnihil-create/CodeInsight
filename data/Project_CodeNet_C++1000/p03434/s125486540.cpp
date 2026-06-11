#include <bits/stdc++.h>
using namespace std;

#define println(msg) cout << msg << endl
#define yes_or_no(flag) if (flag) { println("Yes"); } else { println("No"); }
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define rsort_vec(vec) sort(vec.rbegin(), vec.rend())

int main() {
  // 入力
  int N;
  cin >> N;
    
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  
  // 計算
  rsort_vec(a);
  
  int a_sum = 0;
  int b_sum = 0;
  for (int i = 0; i < a.size(); i += 2) {
    a_sum += a.at(i);
    if (i + 1 < a.size())
      b_sum += a.at(i + 1);
  }
  
  // 出力
  println((a_sum - b_sum));
}