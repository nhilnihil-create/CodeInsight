#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#define graph_from1 true
#define graph_tree true
#define graph_weight false
typedef long long ll;
using namespace std;

class Graph_func
{
public:
	int N;
	int N_edge;
	vector<pair<int, int> > edgelist;
	vector<int> edgeweight;
	vector<vector<int> > adjlist;
	vector<int> adjnum;

	vector<int> xdist;
	vector<bool> x_fixed;

	void read_edge();
	void adjini();
	void adjsort();
	vector<bool> graph_num_sbrt(int x, vector<bool> filled);
	int graph_num();
	void xydist_fill(int x, int dist_tmp);
	void xydist_tree(int x, int dist_tmp);   // ex. xydist_tree(3, 0)
	void xydist(int x, int dist_tmp);   // ex. xydist(3, 0)
	int diameter();
	int leaves_num();

	bool xydist_def = false;
};

void Graph_func::read_edge()
{
	cin >> N;
	if (graph_tree)
		N_edge = N - 1;// graph
	else
		cin >> N_edge;
	edgelist.resize(N_edge);
	edgeweight.resize(N_edge);
	adjnum.resize(N);
	xdist.resize(N);
	adjlist.resize(N);
	//cout << N << " " << N_edge << endl;
	for (int i = 0; i < N_edge; i++)
	{
		if (graph_weight)
			cin >> edgelist[i].first >> edgelist[i].second >> edgeweight[i];
		else
			cin >> edgelist[i].first >> edgelist[i].second;
		if (graph_from1)
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

vector<bool> Graph_func::graph_num_sbrt(int x, vector<bool> filled) // ex. graph_num_sbrt(i, filled);
{
	for (int i = 0; i < adjnum[x]; i++)
	{
		int x_new = adjlist[x][i];
		if (!filled[x_new])
		{
			filled[x_new] = true;
			filled = graph_num_sbrt(x_new, filled);
		}
	}
	return filled;
}

int Graph_func::graph_num()
{
	int anstmp = 0;
	int i = 0;
	vector<bool> filled;
	filled.resize(N);
	for (int j = 0; j < N; j++)
		filled[j] = false;
	bool end = false;
	while (!end)
	{
		if (i >= N)
			break;
		while (1)
		{
			if (!filled[i])
				break;
			i++;
			if (i >= N)
			{
				end = true;
				break;
			}
		}
		if (end)
			break;
		filled[i] = true;
		filled = graph_num_sbrt(i, filled);
		anstmp++;
	}
	return anstmp;
}

void Graph_func::xydist_fill(int x, int dist_tmp)
{
	xdist[x] = dist_tmp;
	x_fixed[x] = true;
}

void Graph_func::xydist_tree(int x, int dist_tmp)  // ex. xydist_tree(3, 0)
{
	if (!xydist_def)
	{
		xydist_def = true;
		x_fixed.resize(N);
		for (int i = 0; i < N; i++)
			x_fixed[i] = false;
		xydist_fill(x, 0);
	}
	//printf("A %d\n", x);
	for (int i = 0; i < adjnum[x]; i++)
	{
		int x_new = adjlist[x][i];
		if (!x_fixed[x_new])
		{
			xydist_fill(x_new, dist_tmp + 1);
			xydist_tree(x_new, dist_tmp + 1);
		}
	}
	return;
}

void Graph_func::xydist(int x, int dist_tmp)  // ex. xydist(3, 0)
{
	if (!xydist_def)
	{
		xydist_def = true;
		x_fixed.resize(N);
		for (int i = 0; i < N; i++)
			x_fixed[i] = false;
		xydist_fill(x, 0);
	}
	for (int i = 0; i < adjnum[x]; i++)
	{
		int x_new = adjlist[x][i];
		if (!x_fixed[x_new])
		{
			xydist_fill(x_new, dist_tmp + 1);
			xydist_tree(x_new, dist_tmp + 1);
		}
	}
	return;
}

int Graph_func::diameter()
{
	int anstmp = 0, anstmp_i = 0;
	pair<int, int> longest;
	xydist_tree(0, 0);
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
	xydist_def = false;
	xydist_tree(longest.first, 0);
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

int Graph_func::leaves_num() // included adjini()
{
	int anstmp = 0;
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
	for (int i = 0; i < N; i++)
	{
		if (adjnum[i] == 1)
			anstmp++;
	}
	return anstmp;
}

int main(void)
{
	Graph_func graph;
	int ans;
	graph.read_edge();
	graph.adjini();
	//ans = graph.graph_num();
	ans = graph.diameter();
	if (ans % 3 != 1)
		cout << "First" << endl;
	else
		cout << "Second" << endl;
	//cout << ans << endl;
	return 0;
}