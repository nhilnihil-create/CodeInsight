#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 100010;

int K;

struct node
{
	int to, len;

	node (int a, int b)
	{
		to = a, len = b;
	}
	node () { }
};
vector <node > link[N];

int dis[N], in[N];
deque <int > q;

void SPFA()
{
	memset(dis, 0x3f, sizeof(dis));
	in[1] = 1, q.push_back(1) , dis[1] = 1;

	while(!q.empty())
	{
		int wz = q.front();
		q.pop_front(), in[wz] = 0;

		for(int k = 0; k < (int )link[wz].size(); k++)
		{
			int to = link[wz][k].to;
			int len = link[wz][k].len;

			if(dis[to] > dis[wz] + len)
			{
				dis[to] = dis[wz] + len;

				if(!in[to])
				{
					in[to] = 1;

					if(q.empty() || dis[to] < dis[q.front()])
						q.push_front(to);
					else
						q.push_back(to);
				}
			}
		}
	}

	printf("%lld", dis[0]);
}

signed main()
{
	scanf("%lld", &K);
	for(int k = 1; k <= K; k++)
		link[k].push_back(node(k + 1, 1)), link[k].push_back(node(k * 10 % K, 0));

	SPFA();

	return 0;
}