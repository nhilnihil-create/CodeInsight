#include <bits/stdc++.h>
using namespace std;

int main() {
  char c[5];
  scanf("%s", c);
  int ans=700;
  for (int i=0; i<3; i++) {
    if ( c[i]=='o' ) ans+=100;
  }
  printf("%d\n", ans);
  return 0; 
}