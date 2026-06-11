#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a, b, turn;
  cin >> N;
  
  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i); 
  }
  
  sort(vec.begin(), vec.end()); // まず sort
  reverse(vec.begin(), vec.end()); // 大きい順に並び替え（先に取る人が大きい数字となるように）
  
  turn = 0; // どっちの手番かを判定
  a, b = 0; // 初期化
  
  for (int i = 0; i < N; i++) {
    if (turn % 2 == 0) { // 最初に取る人＝Alice
      a += vec[i];
    }
    else {
      b += vec[i]; // 後から取る人＝Bob
    }
    turn++;
  }

  cout << a-b << endl;
}
