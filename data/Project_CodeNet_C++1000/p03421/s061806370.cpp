#include<bits/stdc++.h>
#define LL long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=300005,inf=1e8;
int n,m,a,b,ans[N],tot;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	if(n<a+b-1||(LL)a*b<n) {printf("-1\n");return 0;}
	for(int i=1;i<=a;i++) ans[++tot]=(n-a+i);
	m=n-a; n-=a;
	for(int i=b-2;i>=0;i--)
	{
		int k=0;
		if(i<m%(b-1))
		  k=m/(b-1)+1;
		else k=m/(b-1);
		for(int j=n-k+1;j<=n;j++)
		  ans[++tot]=j;
		//cout<<k<<endl;
		n-=k;
	}
	for(int i=1;i<=tot;i++)
	  printf("%d ",ans[i]);
	putchar('\n');
	return 0;
}
//5 6 7 8 3 4 2 1
