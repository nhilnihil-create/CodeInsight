#include <bits/stdc++.h>

using namespace std;

struct Edge
{
	int u, v, c;	

	Edge() {}
	Edge(int x, int y, int z) : u(x), v(y), c(z) {}
};

vector<Edge> res;

int L, N, M;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> L;
	for (int i = 1; i < 19; i++)
	{
		res.emplace_back(Edge(i, i + 1, 1 << (i - 1)));	
		res.emplace_back(Edge(i, i + 1, 0));
	}
	int cur = L;
	for (int i = 19; i > 0; i--)
	{
		while (L >= (1 << i - 1))
		{
			res.emplace_back(Edge(i, 20, cur - L));
			L -= (1 << i - 1);
		}
	}
	N = 20, M = res.size();
	cout << N << " " << M << endl;
	for (int i = 0; i < M; i++)
		cout << res[i].u << " " << res[i].v << " " << res[i].c << endl;	
	return 0;	
}
