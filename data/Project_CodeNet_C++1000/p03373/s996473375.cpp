#include <bits/stdc++.h>
using namespace std;

#define println(msg) cout << msg << endl

int main() {
  // 入力
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  
  // 計算
  int minPrice = INT_MAX;
  int m = max(X, Y);
  for (int c = 0; c <= (2 * m); c++) {
    int a = max(X - c / 2, 0);
    int b = max(Y - c / 2, 0);
    int price = a * A + b * B + c * C;
    minPrice = min(minPrice, price);   
  }
  
  // 出力
  println(minPrice);
}