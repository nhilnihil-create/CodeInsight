#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> m(n);
  for (int i = 0; i < n; i++) cin >> m[i];
  int y = 0, ld = 1001;//yは全部を1つ作った時の重さ,ldは最軽ドーナツの重さ
  for (int i: m) {
    y += i;
    ld = min(ld, i);
  }
  int ldnum = (x - y) / ld;//あと全部ldを作るので追加分のldの数
  int num = n + ldnum;
  cout << num;
}