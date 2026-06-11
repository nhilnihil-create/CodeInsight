#include<cstdio>
using namespace std;
#define N 1050
#define K 36
char as[N][K];
int p[N][2],n,is1,is2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i][0],&p[i][1]);p[i][0]*=-1,p[i][1]*=-1;
		if((p[i][0]+p[i][1])&1)is1=1;
		else is2=1;
	}
	if(is1&&is2){printf("-1\n");return 0;}
	if(is1)
	{
		printf("31\n");
		for(int i=0;i<=30;i++)printf("%d ",1<<i);
		printf("\n");
		for(int i=0;i<30;i++)
		{
			int le=1<<i;
			for(int j=1;j<=n;j++)
			{
				if(p[j][0]>>i&1)
				{
					if(p[j][1]>>i&2)
					{
						int tp1=p[j][0]+le;
						if(tp1>>i&2)p[j][0]-=le,as[j][i]='L';
						else p[j][0]+=le,as[j][i]='R';
					}
					else
					{
						int tp2=p[j][0]-le;
						if(tp2>>i&2)p[j][0]-=le,as[j][i]='L';
						else p[j][0]+=le,as[j][i]='R';
					}
				}
				else
				{
					if(p[j][0]>>i&2)
					{
						int tp1=p[j][1]+le;
						if(tp1>>i&2)p[j][1]-=le,as[j][i]='D';
						else p[j][1]+=le,as[j][i]='U';
					}
					else
					{
						int tp2=p[j][1]-le;
						if(tp2>>i&2)p[j][1]-=le,as[j][i]='D';
						else p[j][1]+=le,as[j][i]='U';
					}
				}
			}
			for(int i=1;i<=n;i++)
			if(p[i][1])as[i][30]=p[i][1]>0?'D':'U';else as[i][30]=p[i][0]>0?'L':'R';
		}
		for(int i=1;i<=n;i++)printf("%s\n",as[i]);
	}
	else
	{
		printf("32\n1 ");
		for(int i=0;i<=30;i++)printf("%d ",1<<i);
		printf("\n");
		for(int i=1;i<=n;i++)p[i][0]--,as[i][0]='L';
		for(int i=0;i<30;i++)
		{
			int le=1<<i;
			for(int j=1;j<=n;j++)
			{
				if(p[j][0]>>i&1)
				{
					if(p[j][1]>>i&2)
					{
						int tp1=p[j][0]+le;
						if(tp1>>i&2)p[j][0]-=le,as[j][i+1]='L';
						else p[j][0]+=le,as[j][i+1]='R';
					}
					else
					{
						int tp2=p[j][0]-le;
						if(tp2>>i&2)p[j][0]-=le,as[j][i+1]='L';
						else p[j][0]+=le,as[j][i+1]='R';
					}
				}
				else
				{
					if(p[j][0]>>i&2)
					{
						int tp1=p[j][1]+le;
						if(tp1>>i&2)p[j][1]-=le,as[j][i+1]='D';
						else p[j][1]+=le,as[j][i+1]='U';
					}
					else
					{
						int tp2=p[j][1]-le;
						if(tp2>>i&2)p[j][1]-=le,as[j][i+1]='D';
						else p[j][1]+=le,as[j][i+1]='U';
					}
				}
			}
			for(int i=1;i<=n;i++)if(p[i][1])as[i][31]=p[i][1]>0?'D':'U';else as[i][31]=p[i][0]>0?'L':'R';
		}
		for(int i=1;i<=n;i++)printf("%s\n",as[i]);
	}
}//