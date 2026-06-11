#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  // 入力読み込み用の配列
  vector<int> mochisize(N);
  // サイズのダブりチェック結果を格納する配列
  vector<int> mochidaburi(N);
  
  // 標準入力から読み込み
  for (int i = 0; i < N; i++) {
    cin >> mochisize.at(i);
  }
  
  // 後にダブりがあるものはフラグを立てる
  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      if (mochisize.at(i) == mochisize.at(j)){
        mochidaburi.at(i) = 1;
        // デバッグ用 ダブったものを出力
//        cout << i  << ":" << mochisize.at(i)  << ":" << mochidaburi.at(i) << endl;
      }
    }
  }
  
  // ダブっている枚数をカウント
  int daburicnt = 0;
  for (int i = 0; i < N; i++) {
    if (mochidaburi.at(i) > 0) {
      daburicnt++;
    }
  }
  
  // ダブりを抜いた枚数を出力する
  cout << N - daburicnt << endl;
  
  return 0;
}