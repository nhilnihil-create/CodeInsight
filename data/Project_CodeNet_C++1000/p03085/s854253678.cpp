#include <cstdio>
using namespace std;
int main() {
  char a[2];
  scanf("%s", a);
  if (a[0] == 'A') printf("T\n");
  else if (a[0] == 'T') printf("A\n");
  else if (a[0] == 'G') printf("C\n");
  else if (a[0] == 'C') printf("G\n");
  return 0;
}