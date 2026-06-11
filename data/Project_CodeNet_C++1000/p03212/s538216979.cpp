#include <iostream>
using namespace std;

// 入力
long long N;

// cur: 現在の値、use: 7, 5, 3 のうちどれを使ったか, cnt: 答え
void func(long long cur, int use, long long &cnt){
  //cout<<cur<<" "<<use<<" "<<cnt<<endl;
  // ベースケース
  if (cur > N) return;
  // 答えを増やす
  if (use == 0b111) ++cnt;

  // 7 を付け加える
  func(cur * 10 + 7, use | 0b001, cnt);

  // 5 を付け加える
  func(cur * 10 + 5, use | 0b010, cnt);

  // 3 を付け加える
  func(cur * 10 + 3, use | 0b100, cnt);
}

int main() {
  cin >> N;
  long long res = 0;
  func(0, 0, res);
  cout << res << endl;
}