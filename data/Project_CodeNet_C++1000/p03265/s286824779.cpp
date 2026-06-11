#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, A, b, B, c, C, d, D;
  cin >> a >> A >> b >> B;

  int dx = b-a; int dy = B-A;
      c = b-dy;
      C = B+dx;
      d = a-dy;
      D = A+dx;
  
  printf("%d %d %d %d\n", c, C, d, D);
}
