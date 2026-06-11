#include <bits/stdc++.h>
using namespace std;

int main() {
  // ここにプログラムを追記
  int A,B,N;
  cin >> N >> A >> B;
  if (A*N > B) cout << B <<endl;
  else if (A*N < B) cout << A*N <<endl;
  else cout << B <<endl;
}