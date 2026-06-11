#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=200005;
vector<int> vec[N];
int n;
int tmp,tmp1;
void dfs (int x,int fa,int dep)
{
	if (dep>tmp1)	{tmp=x;tmp1=dep;}
	int siz=vec[x].size();
	for (int u=0;u<siz;u++)
	{
		int y=vec[x][u];
		if (y==fa) continue;
		dfs(y,x,dep+1);
	}
}
int main()
{
	scanf("%d",&n);
	for (int u=1;u<n;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);vec[y].push_back(x);
	}
	tmp1=0;dfs(1,0,1);
	tmp1=0;dfs(tmp,0,1);
	if (tmp1%3==2) printf("Second\n");
	else printf("First\n");
	return 0;
}