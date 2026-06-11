#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
  char s[100001];
  int n,k;
  scanf("%s",s);
  n=strlen(s);
  k=n;
  for(int i=0;i<n-1;i++)
    if(s[i]!=s[i+1])
      k=min(k,max(i+1,n-i-1));
  printf("%d\n",k);
}