#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
char s[100010];
int main ()
{
	int i,n,ans;
	scanf("%s",s);
	n=strlen(s);
	ans=n;
	for(i=1;i<n;++i)
	  if(s[i-1]!=s[i]) ans=min(ans,max(i,n-i));
	printf("%d",ans);
}