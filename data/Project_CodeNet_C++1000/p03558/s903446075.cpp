#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 99999999999999999
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 100005

struct Edge{
	Edge(int arg_to,int arg_cost){
		to = arg_to;
		cost = arg_cost;
	}
	int to,cost;
};

struct Info{
	Info(int arg_node_id,int arg_sum_cost){
		node_id = arg_node_id;
		sum_cost = arg_sum_cost;
	}
	bool operator<(const struct Info &arg) const{

		return sum_cost > arg.sum_cost; //総コストの昇順(PQ)
	}
	int node_id,sum_cost;
};

int K;
int min_dist[NUM];
vector<Edge> G[NUM];


int main(){

	scanf("%d",&K);

	for(int i = 0; i <= K-1; i++){

		G[i].push_back(Edge((i+1)%K,1)); //コスト1の辺
		G[i].push_back(Edge((10*i)%K,0)); //コスト0の辺
	}

	for(int i = 0; i < K; i++){

		min_dist[i] = BIG_NUM;
	}

	min_dist[1] = 0;

	priority_queue<Info> Q;
	Q.push(Info(1,0));

	int next_node,next_cost;

	while(!Q.empty()){

		if(Q.top().sum_cost > min_dist[Q.top().node_id]){

			Q.pop();
		}else if(Q.top().node_id == 0){

			printf("%d\n",Q.top().sum_cost+1);
			return 0;

		}else{

			for(int i = 0; i < G[Q.top().node_id].size(); i++){

				next_node = G[Q.top().node_id][i].to;
				next_cost = Q.top().sum_cost+G[Q.top().node_id][i].cost;

				if(min_dist[next_node] > next_cost){

					min_dist[next_node] = next_cost;
					Q.push(Info(next_node,next_cost));
				}
			}

			Q.pop();
		}
	}

	return 0;
}
