#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, A, b, B;
  scanf("%d%d%d%d", &a, &A, &b, &B);

  int x = b-a; int y = B-A;

  printf("%d %d %d %d\n", b-y, B+x, a-y, A+x);
}