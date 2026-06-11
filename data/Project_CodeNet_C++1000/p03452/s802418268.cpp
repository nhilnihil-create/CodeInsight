#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<math.h>
#include<unordered_map>
#include<map>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using lst = list<ll>;


vec parent;
vec cost;


int find(int x)
{
	if (parent[x] == x)return x;
	int y = find(parent[x]);
	cost[x] += cost[parent[x]];
	return parent[x] = y;
}


bool unite(int L, int R, int D)
{
	int x = find(L);
	int y = find(R);

	if (x == y)
	{
		return cost[R] - cost[L] == D;
	}

	if (cost[L] + D > cost[R])
	{
		parent[y] = x;
		cost[y] = cost[L] + D - cost[R];
	}
	else
	{
		parent[x] = y;
		cost[x] = cost[R] - D - cost[L];
	}
	return true;
}


int main()
{
	int N, M;
	cin >> N >> M;

	parent = move(vec(N));
	cost   = move(vec(N, 0));
	
	for (int i = 0; i < N; ++i)
	{
		parent[i] = i;
	}

	bool ans = true;

	for(int i=0;i<M;++i)
	{
		int L, R, D;
		cin >> L >> R >> D;
		--L; --R;
		if (!unite(L, R, D))ans = false;
	}
	
	for (int i = 0; i < N; ++i)
	{
		//printf("%d %d %d\n", i+1, find(i)+1, cost[i]);
		find(i);
		if (cost[i] > 1000000000)ans = false;
	}
	


	cout << (ans ? "Yes" : "No") << endl;

	return 0;
}