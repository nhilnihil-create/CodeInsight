#include <iostream>
#include <set>
#include <deque>
#include <vector>
using namespace std;

typedef long long i64;

i64 k;

i64 dist[100010];

struct edge
{
	int to;
	int cost;
};

vector<edge> edges[100010];


int main()
{
	cin >> k;

	for(int i = 0;i < k;i++)
	{
		{
			//plus 1
			int n = i + 1;
			n = n % k;

			edges[i].push_back({n,1});
		}
		{
			//plus * 10

			int n = i * 10;
			n = n % k;
			edges[i].push_back({n,0});
		}
	}
	typedef pair<i64,int> P;

	deque<P> que;
	que.push_back({1,1});
	fill(dist , dist + 100010,(1LL <<60));
	dist[1] = 1;

	while(!que.empty())
	{
		i64 d = que.front().first;
		int v = que.front().second;

		que.pop_front();

		if(dist[v] < d) continue;

		for(edge& e : edges[v])
		{
			if(dist[e.to] > dist[v] + e.cost)
			{
				dist[e.to] = dist[v] + e.cost;
				if(e.cost == 0)
				{
					que.push_front({dist[e.to],e.to});
				}
				else
				{
					que.push_back({dist[e.to],e.to});
				}
			}
		}
	}

	cout << dist[0] << endl;
	return 0;
}

