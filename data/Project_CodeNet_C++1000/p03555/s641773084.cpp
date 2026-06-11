#include <bits/stdc++.h>
using namespace std;

int main() {
  char s[3][5];
  scanf("%s", s[0]);
  scanf("%s", s[1]);
  if(s[0][0]==s[1][2] && s[1][0]==s[0][2] && s[0][1]==s[1][1])
    puts("YES");
  else puts("NO");
  
  return 0;
}
