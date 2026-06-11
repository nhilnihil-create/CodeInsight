#include <iostream>
#include <vector>
using namespace std;
vector<int> v[200005];
pair<int,int> dfs(int node,int p)
{
	pair<int,int> ans={-1,node};
	for (int u:v[node])
	{
		if (u!=p)
		ans=max(ans,dfs(u,node));
	}
	ans.first++;
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	auto a=dfs(1,0),b=dfs(a.second,0);
	if (b.first%3==1)
	printf("Second");
	else
	printf("First");
}