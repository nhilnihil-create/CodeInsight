#include <bits/stdc++.h>
using namespace std;

int main() {
  // 入力される(c11,c12,c13)をs1, (c21,c22,c23)をs2として入力
  string s1, s2;
  cin >> s1 >> s2;

  // s1の1文字目(c11) と s2の3文字目(c23) が同じ
  // かつ
  // s1の3文字目(c13) と s2の1文字目(c21) が同じ
  //
  // この条件を満たす時、180°回転させた時に、元のマス目と一致する。
  if(s1.at(0) == s2.at(2) && s1.at(1) == s2.at(1) && s1.at(2) == s2.at(0)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
