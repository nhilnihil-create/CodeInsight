#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char a[88888888];
int ans=1e9+7;
int main()
{
  scanf("%s",&a);
  for(int i=0;i<strlen(a);i++)
  	if(a[i]!=a[i+1])  ans=min(ans,max(i+1,(int)strlen(a)-i-1));
  printf("%d",min(ans,(int)strlen(a)));
  return 0;
}