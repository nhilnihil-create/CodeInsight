#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  
  int oishi_tabeta_cnt;
  int gedoku_cnt;
  
  // 解毒剤入りのクッキー枚数
  gedoku_cnt = A + B;
  
  if (C < gedoku_cnt -1) {
    // 毒入りクッキーを全部食べられる
    oishi_tabeta_cnt = B + C;
  }
  else {
    // まず毒入りクッキーを食べられた枚数を数える
    oishi_tabeta_cnt = min(C, gedoku_cnt + 1);
    // 解毒剤入り美味しいクッキーを食べられた枚数を数える
    oishi_tabeta_cnt += B;
  }
  cout << oishi_tabeta_cnt << endl;
}
