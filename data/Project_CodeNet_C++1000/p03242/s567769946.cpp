#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
#define maxn 101000

int main()
{
	int len,i;char s[110];
	scanf("%s",s+1);
	len=strlen(s+1);
	for (i=1;i<=len;i++)
	{
		if (s[i]=='1') s[i]='9';
		else if (s[i]=='9') s[i]='1';
	}
	printf("%s\n",s+1);
	return 0;
}
