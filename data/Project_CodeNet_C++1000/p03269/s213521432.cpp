#include<bits/stdc++.h>
#define ll long long
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
int L,a[25],cnt;
int main()
{
	int L=read();
	reg int i,j,N=0,M=0;
	for(i=0;i<=20;++i)if(L>>i&1)a[++cnt]=i-1,++M;
	N=a[cnt]+2;M=M+N*2-3;
	printf("%d %d\n",N,M);
	a[0]=-1;
	for(i=1;i<=cnt;++i)
	{
		for(j=a[i-1];j<a[i];++j)
			printf("%d %d %d\n",j+2,j+3,0),
			printf("%d %d %d\n",j+2,j+3,(1<<(j+1)));
		if(i==cnt) break;
		printf("%d %d %d\n",a[i]+2,N,L-(1<<a[i]+1));
		L-=1<<a[i]+1;
	}
	return 0;
}