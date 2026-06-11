#include <bits/stdc++.h>

using namespace std;

#define M 1000005

int k;
int vis[M];

deque< pair<int, int> > dq;
#define mp(x, y) make_pair(x, y)
#define pi pair<int, int>

void bfs()
{
	dq.push_back(mp(1, 1));
	while (!dq.empty())
	{
		pi x = dq.front(); dq.pop_front();
		if (vis[x.first]) continue; vis[x.first] = 1;
		if (!x.first) { cout << x.second; return; }
		dq.push_front(mp((x.first*10) % k, x.second));
		dq.push_back(mp((x.first+1) % k, x.second + 1));
	}
}

int main()
{
	cin >> k;
	bfs();
	return 0;
}