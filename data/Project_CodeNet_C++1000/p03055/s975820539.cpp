#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>

using namespace std;

#define mod 1000000007

int n;
vector<vector<int> > graph(200001);

pair<int, int> getMaxDistNode(int now)
{
	vector<int> dist(200001, -1);
	dist[now] = 1;
	queue<int> qu;
	qu.push(now);
	while(!qu.empty()){
		int tmp = qu.front();
		qu.pop();
		for(int i = 0; i < graph[tmp].size(); i++){
			int next = graph[tmp][i];
			if(dist[next] >= 0) continue;
			dist[next] = dist[tmp] + 1;
			qu.push(next);
		}
	}
	int ans = 0;
	for(int i = 1; i < n; i++){
		if(dist[i] > dist[ans]) ans = i;
	}
	return make_pair(ans, dist[ans]);
}

int main()
{
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int node1 = getMaxDistNode(0).first;
	int diameter = getMaxDistNode(node1).second;

	bool canWin[200001];
	canWin[0] = false;
	canWin[1] = true;
	canWin[2] = false;
	for(int i = 3; i <= diameter; i++){
		canWin[i] = !canWin[i - 1] || !canWin[i - 2];
	}
	if(canWin[diameter]) cout << "First" << endl;
	else cout << "Second" << endl;

}