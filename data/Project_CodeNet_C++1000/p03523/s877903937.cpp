#include <stdio.h>

char S[55],T[55]="AKIHABARA";

int main()
{
  scanf ("%s",S);
  int i=0,j=0;
  while (S[i]||T[j]){
if (S[i] == T[j]) i++, j++;
    else if ('A' == T[j]) j++;
    else{
      S[i] = 'a';
      break;
    }
  }
  puts(S[i]?"NO":"YES");
return 0;
}
