#include <bits/stdc++.h>
using namespace std;

int main() {
  int currentRating = 0;
  int goalRating = 0;
  
  // 現在のレーティングと、目標のレーティングを入力
  cin >> currentRating >> goalRating;
  
  // 次のコンテストで取るパフォーマンスを出力
  cout << goalRating * 2 - currentRating << endl;
}