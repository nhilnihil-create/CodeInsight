#include<cstdio>
#include<cstring>
using namespace std;
int main(){
  int n;
  char s[51];
  scanf("%s",s);
  n=strlen(s);
  for(int i=0;i<n-8;i++)
    printf("%c",s[i]);
  printf("\n");
}