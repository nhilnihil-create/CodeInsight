#include <stdio.h>
using namespace std;

int main() {
  char a[5][5];
  for (int i=0; i<3; i++) {
    scanf("%s", a[i]);
  }
  
  for (int i=0; i<3; i++) {
    printf("%c", a[i][i]);
  }
  printf("\n");
  return 0; 
}
