#include <bits/stdc++.h>
using namespace std;

int main() {
  // 入力部(N)
  int N;
  cin >> N;

  // 入力部(p1, p2, ... pN)
  vector<int> p(N);
  for(int i = 0; i < N; i++) {
    cin >> p.at(i);
  }

  // 配列pをソート。
  sort(p.begin(), p.end());

  // 配列pの最後尾(最も定価が高い品物の価格)の半額 を最初から引いておく。
  // 意味的には商品の合計を求める前に割引をしているもの。
  int sum = -p.at(N-1) / 2;

  // 全ての品物の価格を sum に加算。
  for(int i = 0; i < N; i++) {
    sum += p.at(i);
  }

  cout << sum << endl;
}
