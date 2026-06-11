#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
  return a > b ? a : b ;
}

int main()
{
  char s[11];
  int i,count=0,ans=0;

  scanf("%s", s);

  for(i=0; i<strlen(s); i++){
    if(s[i] == 'A' || s[i] == 'T' || s[i] == 'G' || s[i] == 'C')
      count++;
    else{
      ans = max(ans,count);
      count = 0;
    }
  }
    ans = max(ans,count);

    printf("%d", ans);
    return 0;
 }
