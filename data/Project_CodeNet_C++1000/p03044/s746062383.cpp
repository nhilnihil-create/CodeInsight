#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 100005

struct Edge{
	Edge(int arg_to,int arg_dist){
		to = arg_to;
		dist = arg_dist;
	}
	int to,dist;
};

int N;
int color[SIZE];
vector<Edge> G[SIZE];

void dfs(int node_id,int pre){

	for(int i = 0; i < G[node_id].size(); i++){

		int child = G[node_id][i].to;
		if(child == pre)continue;

		if(G[node_id][i].dist%2 == 0){

			color[child] = color[node_id];

		}else{

			color[child] = 1-color[node_id];
		}
		dfs(child,node_id);
	}
}

int main(){

	scanf("%d",&N);

	int from,to,dist;

	for(int loop = 0; loop < N-1; loop++){

		scanf("%d %d %d",&from,&to,&dist);
		from--;
		to--;

		dist %= 2;
		G[from].push_back(Edge(to,dist));
		G[to].push_back(Edge(from,dist));
	}

	color[0] = 0;

	dfs(0,-1);

	for(int i = 0; i < N; i++){

		printf("%d\n",color[i]);
	}

	return 0;
}
