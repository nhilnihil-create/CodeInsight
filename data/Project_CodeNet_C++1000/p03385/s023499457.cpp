#include <bits/stdc++.h>
using namespace std;

int main() {
  char s[5];
  scanf("%s",s);
  bool b[3]={0};
  for ( int i=0; i<3; i++ ) {
    b[s[i]-'a']=1;
  }
  if ( b[0] && b[1] && b[2] ) {
    puts("Yes");
  }
  else {
    puts("No");
  }
  return 0;
}
