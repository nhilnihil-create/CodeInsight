#include<bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<=n;i++)
using namespace std;
const int maxn=10005;
int n,m,t;
vector<int> v[maxn];
int main()
{
	scanf("%d",&n);
	n*=2;
	while(m*(m+1)<n) m++;
	if(m*(m+1)!=n)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	m++;
	cout<<m<<endl;
	rep(i,1,m)
	{
		int vv=v[i].size();
		rep(j,vv,m-2)
		{
			t++;
			v[i].push_back(t);
		}
		int e=0;
		rep(j,1,m)
		{
			if(j==i)
			continue;
			v[j].push_back(v[i][e]);
			e++;
		}
		printf("%d ",m-1);
		rep(j,0,m-2)
		{
			printf("%d ",v[i][j]);
		}
		puts("");
	}
	return 0;
}