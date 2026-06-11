#include<stdio.h>
int main() {
  int y, m, d;
  scanf("%d/%d/%d", &y, &m, &d);
  printf("%s",(m >= 5 ? "TBD" : "Heisei"));
  return 0;
}
