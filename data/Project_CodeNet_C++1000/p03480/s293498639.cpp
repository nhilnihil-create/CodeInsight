#include<bits/stdc++.h>
using namespace std;
char p[30000005];int ans=0x3f3f3f3f;
int main()
{
	scanf("%s",&p);
	int ch=strlen(p);
	for(register int i=0;i<ch;i++)
		if(p[i]!=p[i+1])
			ans=min(ans,max(i+1,(int)strlen(p)-i-1));
	if(ans==0x3f3f3f3f)  printf("%d",(int)strlen(p));
	else printf("%d",ans);
	return 0;
}