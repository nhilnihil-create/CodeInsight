#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>>graph(n+1);
	vector<int>indegree(n+1);
	queue<int>q;
	for(int i=1;i<=m;i++)
	{
		int from,to;
		cin>>from>>to;
		graph[from].push_back(to);
		indegree[to]++;
		
}
vector<int>maxDis(n+1);
for(int node=1;node<=n;node++)	
{
	if(indegree[node] == 0)	
	{
		q.push(node);
}
}
int longestPath=0;
while(q.size())
{
	int from = q.front();	
	q.pop();
	longestPath = max(longestPath,maxDis[from]);
	for(auto to : graph[from])
	{
		maxDis[to] = max(maxDis[to],maxDis[from]+1);
		indegree[to]--;
		if(indegree[to]==0)
		{
			q.push(to);
}
}
}
cout<<longestPath<<endl;

}
int  main()
{
	solve();
}




