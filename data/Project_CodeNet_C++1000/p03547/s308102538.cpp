#include <bits/stdc++.h>
using namespace std;
int main(){
  char x, y;
  scanf("%c %c", &x, &y);
  if(x > y) printf(">");
  else if(x < y) printf("<");
  else printf("=");
}
