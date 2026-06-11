#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int K;
  cin >> K;
  
  int A = a;
  int B = b;
  int C = c;
  
  for (int i = 0; i < K; i++) {
    A *= 2;
    B *= 2;
    C *= 2;
  }
  
  A += b + c;
  B += c + a;
  C += a + b;
  
  int ans = A;
  if (ans < B) ans = B;
  if (ans < C) ans = C;
  
  cout << ans << endl;
  
}