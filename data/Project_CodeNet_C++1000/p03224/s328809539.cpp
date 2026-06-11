#include<bits/stdc++.h>
#define maxn 100050
using namespace std;

int n,m;

vector<int> A[maxn];

int main()
{
	scanf("%d",&n);
	for (m=1;m*(m-1)<2*n;++m)	;
	if (m*(m-1)>2*n)
		puts("No");
	else
	{
		int x=0;
		for (int i=1;i<=m;++i)
			for (int j=i+1;j<=m;++j)
				++x,A[i].push_back(x),A[j].push_back(x);
		puts("Yes");
		printf("%d\n",m);
		for (int i=1;i<=m;++i)
		{
			printf("%d ",m-1);
			for (auto x:A[i])
				printf("%d ",x);
			putchar('\n');
		}
	}
	return 0;
}