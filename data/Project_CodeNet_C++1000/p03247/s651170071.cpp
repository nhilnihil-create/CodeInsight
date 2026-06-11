#include<bits/stdc++.h>
#define INF 0x7fffffff
#define LL long long
using namespace std;
LL fx[5]={-1,1,0,0};
LL fy[5]={0,0,-1,1};
LL x[1010],y[1010],cc[50];
char Fx[5]={'L','R','D','U'};
LL read()
{
	LL s=0,fh=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')fh=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+(ch-'0');ch=getchar();}
	return s*fh;
}
LL DIS(LL xx1,LL yy1,LL xx2,LL yy2){return (LL)fabs(xx2-xx1)+(LL)fabs(yy2-yy1);}
int main()
{
	LL i,xx,yy,xx1,yy1,n,s,lcc,mn,jj,k,j,dis;
	bool js,os;
	n=read();
	js=os=false;
	for(i=1;i<=n;i++){x[i]=read();y[i]=read();s=(LL)fabs(x[i])+(LL)fabs(y[i]);if(s%2LL==0LL)os=true;else js=true;}
	if(js==true&&os==true){printf("-1");return 0;}
	else
	{
		lcc=0LL;for(i=30LL;i>=0LL;i--)cc[++lcc]=(1LL<<i);
		if(((LL)fabs(x[1])+(LL)fabs(y[1]))%2LL==0LL)cc[++lcc]=1LL;
		printf("%lld\n",lcc);
		for(i=1;i<=lcc;i++)printf("%lld ",cc[i]);
		printf("\n");
		for(i=1;i<=n;i++)
		{
			xx=0LL;yy=0LL;
			for(k=1;k<=lcc;k++)
			{
				mn=INF;jj=0LL;
				for(j=0;j<=3;j++)
				{
					xx1=xx+fx[j]*cc[k];yy1=yy+fy[j]*cc[k];
					dis=DIS(xx1,yy1,x[i],y[i]);
					if(dis<mn)
					{
						mn=dis;
						jj=j;
					}
				}
				printf("%c",Fx[jj]);
				xx=xx+fx[jj]*cc[k];yy=yy+fy[jj]*cc[k];
			}
			printf("\n");
		}
	}
	return 0;
}