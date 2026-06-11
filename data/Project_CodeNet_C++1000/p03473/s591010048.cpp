#include <bits/stdc++.h>
using namespace std;

int main() {
  // 変数設定
  int m; // 入力値
  int PRAVE_LAST_DATE_TIME = 24; // 12月30日の時間合計
  int LAST_DATE_TIME = 24; // 12月31日の時間数
  int result; // 出力結果
  
  // 入力
  cin >> m;
  
  // 計算処理
  result = PRAVE_LAST_DATE_TIME - m + LAST_DATE_TIME;
  
  // 出力
  cout << result << endl;
}