#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin >> a;
  int result;
  // １００の位の結果を保存
  result = a / 100;
  // 10の位の結果を保存
  a -= (result * 100);
  result += a / 10;
  // 1のくらいの結果を保存
  result += a % 2;

  cout << result << endl;
  return 0;
}
  