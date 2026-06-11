#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  int X = max(A, B);
  int Y = min(A, B);
  int ans = X;
  int M =max(X-1,Y);
  ans += M;
  cout << ans;
}
