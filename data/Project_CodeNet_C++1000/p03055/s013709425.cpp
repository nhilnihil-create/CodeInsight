#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#include <queue>
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
	vector<ll> edgeweight;
	vector<vector<int> > adjlist;
	vector<vector<ll> > adjlistweight;
	vector<int> adjnum;

	vector<ll> xdist;
	
	vector<bool> x_visited;
	vector<int> x_prqarr;
	vector<bool> x_filled;

	void read_edge();
	void adjini();
	void visited_ini();
	void adjsort();
	vector<bool> graph_num_sbrt(int x, vector<bool> filled);
	int graph_num();
	void graph_BFS(ll BFS_ini);
	void graph_DFS_1(ll DFS_ini);
	void graph_DFS(int x);
	void xydist_fill(int x, ll dist_tmp);
	void xydist_tree(int x, ll dist_tmp);   // ex. xydist_tree(3, 0)
	void xydist(int x);   // ex. xydist(3, 0)
	ll diameter();
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
	if(graph_weight)
		adjlistweight.resize(N);
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
		if (graph_weight)
		{
			ll xyweight = edgeweight[i];
			adjlistweight[x].push_back(xyweight);
			adjlistweight[y].push_back(xyweight);
		}
		adjnum[x]++;
		adjnum[y]++;
	}
	x_visited.resize(N);
	for (int i = 0; i < N; i++)
		x_visited[i] = false;

	return;
}

void Graph_func::visited_ini()
{
	for (int i = 0; i < N; i++)
		x_visited[i] = false;
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

void Graph_func::graph_BFS(ll BFS_ini)
{
	x_prqarr.push_back(BFS_ini);
	x_visited[BFS_ini] = true;

	while (!x_prqarr.empty())
	{
		int Ntmp = x_prqarr.size();
		for (int a = 0; a < Ntmp; a++)
		{
			int x = x_prqarr[0];
			x_prqarr.erase(x_prqarr.begin());
			for (int i = 0; i < adjnum[x]; i++)
			{
				int x_new = adjlist[x][i];
				if (!x_visited[x_new])
				{
					x_prqarr.push_back(x_new);
					x_visited[x_new] = true;
					cout << x_new << endl;
				}
			}
		}
	}
	return;
}

void Graph_func::graph_DFS_1(ll DFS_ini)
{
	x_prqarr.push_back(DFS_ini);
	x_visited[DFS_ini] = true;
	xdist[DFS_ini] = 0;
	
	while (!x_prqarr.empty())
	{
		int Ntmp = x_prqarr.size();
		for (int a = 0; a < Ntmp; a++)
		{
			int x = x_prqarr[x_prqarr.size() - 1];
			x_prqarr.pop_back();
			for (int i = 0; i < adjnum[x]; i++)
			{
				int x_new = adjlist[x][i];
				if (!x_visited[x_new])
				{
					xdist[x_new] = xdist[x] + 1;
					x_prqarr.push_back(x_new);
					x_visited[x_new] = true;
				}
			}
		}
	}
	return;
}

void Graph_func::graph_DFS(int x)
{
	x_visited[x] = true;
	for (int i = 0; i < adjnum[x]; i++)
	{
		int x_new = adjlist[x][i];
		if (!x_visited[x_new])
		{
			cout << x_new << endl;
			graph_DFS(x_new);
		}
	}
	return;
}

void Graph_func::xydist_fill(int x, ll dist_tmp)
{
	xdist[x] = dist_tmp;
	x_visited[x] = true;
}

void Graph_func::xydist_tree(int x, ll dist_tmp)  // ex. xydist_tree(3, 0), DFS
{
	if (!xydist_def)
	{
		xydist_def = true;
		xydist_fill(x, 0);
	}
	for (int i = 0; i < adjnum[x]; i++)
	{
		int x_new = adjlist[x][i];
		if (!x_visited[x_new])
		{
			xydist_fill(x_new, dist_tmp + 1);
			xydist_tree(x_new, dist_tmp + 1);
		}
	}
	return;
}

void Graph_func::xydist(int x)  // ex. xydist(3), Dijkstra's algorithm
{
	priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > xdist_que; //Alive_vertices
	ll max_tmp = pow(10, 18) * 4;
	for (int i = 0; i < N; i++)
		xdist[i] = max_tmp;
	xdist[x] = 0;
	pair<ll, int> xdist_que_tmp;
	xdist_que_tmp.first = 0;
	xdist_que_tmp.second = x;
	xdist_que.push(xdist_que_tmp);
	while (!xdist_que.empty())
	{
		xdist_que_tmp = xdist_que.top();
		xdist_que.pop();
		ll xdist_tmp = xdist_que_tmp.first;
		int x_tmp = xdist_que_tmp.second;
		if (xdist[x_tmp] == xdist_tmp)
		{
			for (int i = 0; i < adjnum[x_tmp]; i++)
			{
				int x_new = adjlist[x_tmp][i];
				ll dist_diff;
				if(graph_weight)
					dist_diff = adjlistweight[x_tmp][i];
				else dist_diff = 1;
				if (xdist[x_new] > xdist[x_tmp] + dist_diff)
				{
					xdist[x_new] = xdist[x_tmp] + dist_diff;
					xdist_que_tmp.first = xdist[x_new];
					xdist_que_tmp.second = x_new;
					xdist_que.push(xdist_que_tmp);
				}
			}
		}
	}
}

ll Graph_func::diameter()
{
	ll anstmp = 0, anstmp_i = 0;
	pair<int, int> longest;
	if (graph_tree)
		xydist_tree(0, 0);
	else
		graph_DFS_1(0);
		//xydist(0);
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
	visited_ini();
	if (graph_tree)
		xydist_tree(longest.first, 0);
	else
		graph_DFS_1(longest.first);
		//xydist(longest.first);
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
	ll ans;
	graph.read_edge();
	graph.adjini();
	//graph.graph_DFS_1();
	//ans = graph.graph_num();
	ans = graph.diameter();
	//graph.xydist_def = false;
	//graph.xydist(0);
	//cout << endl;
	/*for (int u = 0; u < graph.N; u++)
	{
		ans = graph.xdist[u];
		cout << u << " " << ans << endl;
	}*/
	if (ans % 3 != 1)
		cout << "First" << endl;
	else
		cout << "Second" << endl;
	//cout << ans << endl;
	return 0;
}