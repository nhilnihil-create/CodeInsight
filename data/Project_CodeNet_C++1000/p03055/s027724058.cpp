#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#define nmax_def 110000
#define start_from1 true
typedef long long ll;
using namespace std;

class Graph_func
{
public:
	int N;
	int N_edge;
	vector<pair<int, int> > edgelist;
	vector<vector<int> > adjlist;
	vector<int> adjnum;

	vector<int> xdist;

	void read_edge();
	void adjini();
	void adjsort();
	void xydist(int x, int x_old, int dist_tmp);   // ex. xydist(3, N, 0)
	int diameter();
};

void Graph_func::read_edge()
{
	cin >> N;
	N_edge = N - 1;// graph

	edgelist.resize(N_edge);
	adjnum.resize(N);
	xdist.resize(N);
	adjlist.resize(N);
	//cout << N << " " << N_edge << endl;
	for (int i = 0; i < N_edge; i++)
	{
		cin >> edgelist[i].first >> edgelist[i].second;
		if (start_from1)
		{
			edgelist[i].first--;
			edgelist[i].second--;
		}
	}
	return;
}

void Graph_func::adjini()
{
	for (int i = 0; i < N; i++)
		adjnum[i] = 0;
	for (int i = 0; i < N_edge; i++)
	{
		int x = edgelist[i].first;
		int y = edgelist[i].second;
		adjlist[x].push_back(y);
	    adjlist[y].push_back(x);
		adjnum[x]++;
		adjnum[y]++;
	}
	return;
}

void Graph_func::adjsort()
{
	for (int i = 0; i < N; i++)
		sort(adjlist[i].begin(), adjlist[i].end(), less<int>());
	return;
}

void Graph_func::xydist(int x, int x_old, int dist_tmp)  // ex. xydist(3, N, 0)
{
	if (x_old == N)
		xdist[x] = 0;
	for (int i = 0; i < adjnum[x]; i++)
	{
		int x_new = adjlist[x][i];
		if (x_new != x_old)
		{
			xdist[x_new] = dist_tmp + 1;
			xydist(x_new, x, dist_tmp + 1);
		}
	}
	return;
}

int Graph_func::diameter()
{
	int anstmp = 0, anstmp_i = 0;
	pair<int, int> longest;
	xydist(0, N, 0);
	//for (int i = 0; i < N; i++)
		//cout << xdist[i] << endl;
	for (int i = 0; i < N; i++)
	{
		if (xdist[i] > anstmp)
		{
			anstmp = xdist[i];
			anstmp_i = i;
		}
	}
	longest.first = anstmp_i;
	anstmp = 0, anstmp_i = 0;
	xydist(longest.first, N, 0);
	for (int i = 0; i < N; i++)
	{
		if (xdist[i] > anstmp)
		{
			anstmp = xdist[i];
			anstmp_i = i;
		}
	}
	longest.second = anstmp_i;
	return anstmp;
}

int main(void)
{
	Graph_func graph;
	int ans;
	graph.read_edge();
	graph.adjini();
	ans = graph.diameter();
	//cout << ans << endl;
	if (ans % 3 != 1)
		cout << "First" << endl;
	else
		cout << "Second" << endl;
	return 0;
}