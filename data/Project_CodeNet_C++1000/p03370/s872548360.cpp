#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  
  vector<int> m(N);
  for(int i = 0; i < N; i++) {
    cin >> m.at(i);
  }

  // 最低一個 => 粉が何グラムで、何個
  auto g = accumulate(m.begin(), m.end(), 0);
  int num = m.size();
  
  // 一番粉が少なくて良いやつを探す
  sort(m.begin(), m.end());
  auto i = min(m.begin(), m.end());
  int m1 = *i;  
  
  // 追加で何個作れるか
  num += ((X - g) / m1);
  
  // 出力
  cout << num << endl;
}
