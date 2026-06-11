#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a,b;
	set<int> edge[n];
	for (int i = 0; i < n-1; ++i)
	{
		cin>>a>>b;--a;--b;
		edge[a].insert(b);
		edge[b].insert(a);
	}
	int c[n];
	long long s=0LL;
	for (int i = 0; i < n; ++i)
	{
		cin>>c[i];
		s+=(long long)c[i];
	}
	sort(c,c+n);
	reverse(c,c+n);
	cout<<(long long)s-c[0]<<endl;
	queue<int> que;
	int memo[n]={},d[n],cnt=0;
	que.push(0);
	memo[0]=1;
	while (cnt<n)
	{
		int now=que.front();que.pop();
		d[now]=c[cnt];
		++cnt;
		for (auto i = edge[now].begin(); i != edge[now].end(); ++i)
		{
			if (memo[*i]==0)
			{
				memo[*i]=1;
				que.push(*i);
			}
		}
	}
	cout<<d[0];
	for (int i = 1; i < n; ++i)
	{
		cout<<" "<<d[i];
	}
	cout<<endl;
	return 0;
}
