#include <bits/stdc++.h>
using namespace std;

int main() {
  char A, B, C, D;
  scanf("%c%c%c%c", &A, &B, &C, &D);
  int a = A - '0', b = B - '0', c = C - '0', d = D - '0';
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      for(int k = 0; k < 2; k++) {
        char op1 = (i == 0)? '+': '-', op2 = (j == 0)? '+': '-', op3 = (k == 0)? '+': '-';
        int sum = a;
        sum = i == 0? (sum + b): (sum - b);
        sum = j == 0? (sum + c): (sum - c);
        sum = k == 0? (sum + d): (sum - d);
        if(sum == 7) {
          printf("%d%c%d%c%d%c%d=7", a, op1, b, op2, c, op3, d);
          goto OUT;
        }
      }
    }
  }
  OUT:;
}