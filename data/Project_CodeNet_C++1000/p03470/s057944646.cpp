// ABC 085 B- Kagami Mochi

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  // Kagami Mochi 配列
  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  // 大きい順に並べる
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());

  // 同じ大きさがないか確認
  int count = 1;
  if (N == 1) {
    cout << count << endl;
  }
  else {
    for (int i = 0; i < N-1; i++) {
      if (vec.at(i) != vec.at(i+1)) {
        count++;
      }
    }
  cout << count << endl;
  }
}
