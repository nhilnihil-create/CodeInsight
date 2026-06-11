#include <bits/stdc++.h>
using namespace std;

/*
1秒間に上下左右いずれかに1しか動かないので、abs(x(i+1)-x(i)) + abs(y(i+1)-y(i))
の解は1秒ごとに偶数か奇数の値を取る。
地点(0,0)から始まるので、1秒後には奇数、2秒後には偶数、と、秒数と同じ偶奇を取る。
よって、t(i+1)とt(i)、(x(i+1),y(i+1))と(x(i),y(i))それぞれの差の偶奇が一致していれば
実現可能ということになる。
*/

int main() {
  int N;
  cin >> N;
  
  vector<int> t(100010), x(100010), y(100010);
  // 差を求めたいのでindex 0は0にしておき, index 1から値を挿入する
  for (int i = 0; i < N; i++) cin >> t.at(i+1) >> x.at(i+1) >> y.at(i+1);
  
  bool possible = true;
  for (int i = 0; i < N; i++) {
    int d_time = t.at(i+1) - t.at(i);
    int d_pos = abs(x.at(i+1) - x.at(i)) + abs(y.at(i+1) - y.at(i));
    if (d_pos > d_time) possible = false;  // d_pos > d_timeの場合もう不可能確定
    if (d_time % 2 != d_pos % 2) possible = false;  // 偶奇不一致の場合不可能
  }
  
  cout << (possible ? "Yes" : "No") << endl;
}

/*
各秒の動きをシミュレーションしても良し。

int current_t = 0, current_x = 0, current_y = 0;  // 初期時刻と位置
bool possible = true;
for (int i = 0; i < N; i++) {
  int t, x, y;
  cin >> t >> x >> y;  // 目的時刻と位置
  for (; current_t < t; current_t++) {
    // x(or y)がcurrent_x(or y)より小さければ戻る(-1)。大きければ進む(1)
    if (current_x != x) current_x += (x < current_x) ? -1 : 1;  // xがずれてるならxを調整
    else current_y += (y < current_y) ? -1 : 1;  // そうでないならyを調整
  }
  // 目的時刻に目的位置に辿り着いていないならfalse
  if (current_x != x || current_y != y) possible = false;
}
*/