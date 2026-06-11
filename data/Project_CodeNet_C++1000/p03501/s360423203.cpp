#include <bits/stdc++.h>
using namespace std;

int main() {
  // ここにプログラムを追記
  
  int N, A, B;
  cin >> N >> A >> B;
  
  //プラン１
  int a = N * A;
  
  //安い方
  int x = min(a, B);
  
  cout << x << endl;
  
  return 0;
  
}