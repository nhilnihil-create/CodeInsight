#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int b[50],x[maxn],y[maxn],cnt;
char ans[50];

int main()
{
	int n=read(),f=0;
	for(int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	int tmp=abs(x[1]+y[1])%2;
	for(int i=2;i<=n;i++) if(abs(x[i]+y[i])%2!=tmp) f=1;
	if(f==1) {puts("-1"); return 0;}
	if(tmp==0) b[++cnt]=1;
	for(int i=0;i<=30;i++) b[++cnt]=(1<<i);
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++) printf("%d ",b[i]); puts("");
	for(int i=1;i<=n;i++)
	{
		int nx=-x[i],ny=-y[i],tx,ty;
		for(int j=cnt;j>=1;j--)
		{
			if(abs(nx)>abs(ny))
			{
				if(nx>0) nx-=b[j],ans[j]='L';
				else nx+=b[j],ans[j]='R';
			}
			else
			{
				if(ny>0) ny-=b[j],ans[j]='D';
				else ny+=b[j],ans[j]='U';
			}
		}
		//cout<<nx<<" "<<ny<<endl;
		for(int j=1;j<=cnt;j++) printf("%c",ans[j]); puts("");
	}
	return 0;
}