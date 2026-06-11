#include <bits/stdc++.h>
using namespace std;
// for (int i = 0, i < N, i++) {
// strint'', char'
// エスケープシークエンス改行になる\n　cout << "こんにちは\nAtCoder";
// 行全て取り出す　getline(cin, 文字列変数);
// 配列　vector<型> vec(要素数, 初期値);　　vec.at(i)　　vec.size()
// int型 data[要素数]; // Cの配列
// 逆順に並び替え　reverse(配列変数.begin(), 配列変数.end());
// 小さい順に並び替え　sort(配列変数.begin(), 配列変数.end());





int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec.at(i);
  }
  sort(vec.begin(), vec.end());
  int count = 1;
  for (int i = 0; i < n-1; i++) {
    if (vec.at(i) != vec.at(i+1)) {
      count++;
    }
  }
  cout << count << endl;
}
