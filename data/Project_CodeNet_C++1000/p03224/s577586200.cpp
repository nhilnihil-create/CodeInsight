#include<cstdio>
#include<iostream>
#include<cstring>
#define RG register
using namespace std;
int n,col[450][450],cnt[450],tt;
template<typename I>inline void read(I&ot){
	I ch=getchar(), x=0, f=1;
	while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0' && ch<='9'){x=10*x+ch-'0'; ch=getchar();}
	ot=x*f;}
template<typename I,typename... U>inline void read(I&x,U&... y){read(x); read(y...);}
int main()
{
//	freopen(".in","r",stdin);
	read(n);
	for(int i=2;i*(i-1)/2<=n;i++)
	{
		if(i*(i-1)/2==n)
		{
			printf("Yes\n%d\n",i);
			for(int j=1;j<i;j++)
			{
				for(int k=j+1;k<=i;k++)
				{
					col[j][++cnt[j]]=++tt;
					col[k][++cnt[k]]=tt;
				}
				printf("%d ",cnt[j]);
				for(int k=1;k<=cnt[j];k++) printf("%d ",col[j][k]); printf("\n");
			}
			printf("%d ",cnt[i]); for(int k=1;k<=cnt[i];k++) printf("%d ",col[i][k]);
			return 0;
		}
	}
	printf("No\n");
//	fclose(stdin); fclose(stdout);
	return 0;
}