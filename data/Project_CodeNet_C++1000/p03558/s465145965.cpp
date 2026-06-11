#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
int dis[N];
int vis[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	MEM(dis, 0x3f);
	cin >> n;
	typedef pair<int, int> Node;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	for (int i = 1; i < 10; i++)
	{
		dis[i%n] = i;
		pq.emplace(dis[i%n], i);
	}
	while (!pq.empty())
	{
		int x, d;
		tie(d, x) = pq.top();
		pq.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (int i = 0; i < 10; i++)
		{
			int o = (x * 10 + i) % n;
			if (dis[o] > d + i)
			{
				dis[o] = d + i;
				pq.emplace(dis[o], o);
			}
		}
	}
	cout << dis[0] << endl;
	return 0;
}
