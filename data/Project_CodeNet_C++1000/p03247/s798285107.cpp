#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
int n,t,tot;
LL nowx,nowy,dx,dy;
int x[1010],y[1010],len[33];
char s[40];
int jue(int x){return x>0?x:-x;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%d%d",&x[i],&y[i]);
	t=jue(x[1]+y[1])&1;
	for(int i=1;i<=n;++i)
		if((jue(x[i]+y[i])&1)!=t)return puts("-1")==2333;
	cout<<32-t<<endl;
	len[tot=1]=1;printf("%d ",1);
	for(int i=t;i<=30;++i)printf("%d ",len[++tot]=1<<i);puts("");
	for(int i=1;i<=n;++i)
	{
		nowx=0;nowy=0;
		for(int j=tot;j>=1;--j)
		{
			dx=x[i]-nowx;dy=y[i]-nowy;
			if(jue(dx)>jue(dy))
			{
				if(dx>0)nowx+=len[j],s[j]='R';
				else nowx-=len[j],s[j]='L';
			}
			else
			{
				if(dy>0)nowy+=len[j],s[j]='U';
				else nowy-=len[j],s[j]='D';
			}
		}
		printf("%s\n",s+1);
	}
	return 0;
}