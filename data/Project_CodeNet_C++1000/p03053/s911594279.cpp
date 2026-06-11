#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional> 
#include <iomanip>
#include <unordered_map>
#include <memory.h>
#include <cstring>
#include <fstream>

using namespace std;

int dist[1001][1001];
char board[1001][1001];
int n, m;
const int INF = 1e9;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pque;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == '#')
			{
				dist[i][j] = 0;
				pque.push(make_pair(dist[i][j], make_pair(i, j)));
			}
			else
			{
				dist[i][j] = INF;
			}
		}
	}

	while (!pque.empty())
	{
		int y = pque.top().second.first;
		int x = pque.top().second.second;
		pque.pop();

		for (int k = 0; k < 4; k++)
		{
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
			{
				continue;
			}
			if (dist[ny][nx] > dist[y][x] + 1)
			{
				dist[ny][nx] = dist[y][x] + 1;
				pque.push(make_pair(dist[ny][nx], make_pair(ny, nx)));
			}
		}
	}

	int res = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			res = max(res, dist[i][j]);
		}
	}

	cout << res << '\n';

	return 0;
}