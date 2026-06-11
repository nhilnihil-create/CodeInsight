#include <stdio.h>
 
int main() {
  int A, B, pc = 0;
  char S[20];
  scanf("%d %d %s", &A, &B, S);
  for (int i = 0; S[i] != '\0'; i++) {
    (S[i] == '-') ? pc += i + 1 : pc == 0;
  }
  pc == A + 1 ? printf("Yes") : printf("No");
  
  return 0;
}