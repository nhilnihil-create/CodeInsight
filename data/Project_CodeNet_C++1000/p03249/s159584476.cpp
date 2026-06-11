#include <bits/stdc++.h>

using namespace std;

int N;
map<long long,int> id;
long long seq[100050];
int sz[100050];
vector<int> v[100050];
long long ans = 0;

void Serval(int pos,int dep,int lst)
{
	ans += dep;
	for(int i = 0;i < v[pos].size(); ++ i)
	{
		int nxt = v[pos][i];
		if(nxt != lst)
			Serval(nxt,dep + 1,pos);
	}
}

int main()
{
	scanf("%d",&N);
	for(int i = 1;i <= N; ++ i)
		scanf("%lld",&seq[i]),id[seq[i]] = i,sz[i] = 1;
	sort(seq + 1,seq + 1 + N);
	for(int i = N;i >= 2; -- i)
	{
		int delta = N - 2 * sz[id[seq[i]]];
		if(delta < 0)
		{
			printf("-1\n");
			return 0;
		}
		long long to_find = seq[i] - delta;
		if(!id.count(to_find))
		{
			printf("-1\n");
			return 0;
		}
		sz[id[to_find]] += sz[id[seq[i]]];
		v[id[seq[i]]].push_back(id[to_find]);
		v[id[to_find]].push_back(id[seq[i]]);
	}
	Serval(id[seq[1]],0,0);
	if(ans != seq[1])
	{
		printf("-1\n");
		return 0;
	}
	for(int i = 1;i <= N; ++ i)
	{
		for(int j = 0;j < v[i].size(); ++ j)
		{
			int nxt = v[i][j];
			if(nxt > i) printf("%d %d\n",i,nxt);
		}
	}
}