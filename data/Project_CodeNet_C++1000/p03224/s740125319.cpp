#include<bits/stdc++.h>
#define il inline
#define rg register
#define ldb double
#define lst long long
#define rgt register int
#define N 100050
using namespace std;
const int Inf=1e9;
il int MAX(rgt x,rgt y){return x>y?x:y;}
il int MIN(rgt x,rgt y){return x<y?x:y;}
il int read()
{
	int s=0,m=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')m=1;ch=getchar();}
	while( isdigit(ch))s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return m?-s:s;
}

int n,K;
vector<int> V[N];

int main()
{
	n=read();
	for(rgt k=1;k<=n+1;++k)
		if(k*(k-1)/2==n)K=k;
	if(!K)puts("No");
	else
	{
		rgt tot=1;
		for(rgt i=1;i<K;++i)
			for(rgt j=i+1;j<=K;++j)
			{
				V[i].push_back(tot);
				V[j].push_back(tot);
				++tot;
			}
		puts("Yes");
		printf("%d\n",K);
		for(rgt i=1;i<=K;++i)
		{
			rgt Sz=V[i].size();
			printf("%d ",Sz);
			for(rgt j=0;j<Sz-1;++j)
				printf("%d ",V[i][j]);
			printf("%d\n",V[i][Sz-1]);
		}
	}
	return 0;
}