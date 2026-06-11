#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; // 餅の枚数
  cin >> N;
  
  int mochimax = 100; // 餅のサイズのバリエーション
  
  // サイズごとの餅の有無を格納する配列
  vector<int> mochisize(mochimax + 1);
  
  // 標準入力から読み込み、餅サイズ有無を保存
  for (int i = 0; i < N; i++) {
    int cur_mochisize;
    cin >> cur_mochisize;
    mochisize.at(cur_mochisize) = mochisize.at(cur_mochisize) + 1;
//    cout << i << " " << mochisize.at(cur_mochisize) << endl;
  }
  
  // 餅サイズのサイズのバリエーションをカウント
  int mochicnt = 0;
  for (int i = 0; i < mochimax + 1 ; i++) {
    if (mochisize.at(i) > 0) {
      mochicnt++;
    }
  }
  
  // 餅サイズのバリエーションを出力
  cout << mochicnt << endl;
  
  return 0;
}