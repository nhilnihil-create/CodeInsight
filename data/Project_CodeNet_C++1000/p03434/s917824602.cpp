// ABC 088 B- Card Game for Two

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  // 得点を大きい順にする
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());

  // 偶数(Alice)と奇数(Bob)でそれぞれ点数を足し合わせる
  int pl = 0, mi = 0; // カウントする系なのは初期値設定しておこう
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) {
      pl += vec.at(i);
    }
    else {
      mi += vec.at(i);
    }
  }
  cout << pl - mi << endl;
}
