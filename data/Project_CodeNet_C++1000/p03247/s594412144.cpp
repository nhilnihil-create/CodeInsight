#include<bits/stdc++.h>
using namespace std;

int n,m,cnt;
int x[1010],y[1010];

inline int read()
{
	int x=0,f=1;char c=getchar();
	while (c<'0' || c>'9') {if (c=='-') f=0;c=getchar();}
	while (c>='0' && c<='9') x=x*10+(c^48),c=getchar();
	return f?x:-x;
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		x[i]=read(),y[i]=read();
		if ((x[i]+y[i])&1) cnt--;
		else cnt++;
	}
	if (abs(cnt)!=n) {printf("-1\n");return 0;}
	m=31+(cnt>0);
	printf("%d\n",m);
	for (int i=0;i<=30;i++) printf("%d ",1<<i);
	if (cnt>0) printf("1 ");
	printf("\n");char s[40];
	for (int i=1;i<=n;i++)
	{
		memset(s,0,sizeof(s));
		int X=x[i],Y=y[i];
		bool flag=0;
		if (cnt>0) s[31]='R',X--;
		for (int j=30;j>=0;j--)
		{
			if (abs(X)<abs(Y)) swap(X,Y),flag^=1;
			if (X>0) X-=1<<j,s[j]=flag?'U':'R';
			else X+=1<<j,s[j]=flag?'D':'L';
		}
		printf("%s\n",s);
	}
}