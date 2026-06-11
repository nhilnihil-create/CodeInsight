#include <bits/stdc++.h>
using namespace std;

#define println(msg) cout << msg << endl
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define rsort_vec(vec) sort(vec.rbegin(), vec.rend()) // greater<int>()

int main() {
  // 入力
  int N;
  cin >> N;

  vector<int> d(N);
  for (int i = 0; i < N; i++) {
    cin >> d.at(i);
  }
  
  // 計算
  
  // 重複をけす
  set<int> tmp;
  for (int i = 0; i < N; i++) {
    tmp.insert(d.at(i));
  }
  
  // 出力
  println(tmp.size());
}
