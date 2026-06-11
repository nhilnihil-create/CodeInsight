#include <bits/stdc++.h>
using namespace std;

int main() {
  // 入力される(c11,c12,c13)をs1, (c21,c22,c23)をs2として入力
  string s1, s2;
  cin >> s1 >> s2;

  // s2をreverse関数を用いて反転させる
  reverse(s2.begin(), s2.end());

  //「s1」と「反転させたs2」が同じなら 'YES' と表示
  if(s1 == s2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
