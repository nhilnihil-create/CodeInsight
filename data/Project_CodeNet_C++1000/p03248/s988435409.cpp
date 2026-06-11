#include <bits/stdc++.h>

using namespace std;

int n;
char s[500010];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	if(s[1]=='0'||s[n]=='1')
	{
		puts("-1");
		return 0;
	}
	for(int i=2;i<=n-1;i++)
		if(s[i]!=s[n-i])
		{
			puts("-1");
			return 0;
		}
	int tmp=2,pr=1;
	while(tmp<=n)
	{
		int st=tmp; 
		printf("%d %d\n",pr,st);
		while(s[tmp]=='0') tmp++;
		for(int j=st+1;j<=min(n,tmp);j++)
			printf("%d %d\n",st,j);
		tmp++; pr=st;
	}
	return 0;	
}