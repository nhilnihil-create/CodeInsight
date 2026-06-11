#include<bits/stdc++.h>
using namespace std;
const int N=15;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
char s[N];

signed main()
{
	int n=read(),a=0,b=0,ba=0,ans=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		int m=strlen(s+1);
		for (int j=1;j<m;j++)
		if (s[j]=='A'&&s[j+1]=='B')
		ans++;
		if (s[1]=='B'&&s[m]=='A') ba++;
		else
		{
			if (s[1]=='B') b++;
			if (s[m]=='A') a++;
		}
	}
	if (ba) ans+=ba-1;
	if (ba)
	{
		if (a) a--,ans++;
		if (b) b--,ans++;
	}
	ans+=min(a,b);
	print(ans);

	return 0;
}