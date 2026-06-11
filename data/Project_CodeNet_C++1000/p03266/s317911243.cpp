#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef unsigned long long int ll;


struct edge{
	int to,cost;
};

typedef vector<vector<edge>> adjList;
typedef pair<int,int> P;
const int INF = 1e9;
vector<int> dist;
adjList graph;

void dijkstra(int n,int s){
	dist = vector<int>(n,INF);
	dist[s] = 0;
	priority_queue<P,vector<P>,greater<P>> que;
	que.push(make_pair(0,s));
	while( ! que.empty()){
		P p = que.top();
		que.pop();
		int v = p.second;
		if(dist[v] < p.first){
			continue;
		}
		for(int i = 0; i < graph[v].size(); i++){
			edge e = graph[v][i];
			if( dist[e.to] > dist[v] + e.cost){
				dist[e.to] = dist[v] + e.cost;
				que.push(make_pair(dist[e.to],e.to));
			}
		}
	}
}


int main()
{
	int n,k;
	cin>>n>>k;
	ll ans = 0;
	ll a;
	if( k % 2 == 0){
		int half = k / 2;
		if( (n % k ) >= half){
			a = (n/k) + 1;
		}else{
			a = n/k;
		}
		ans += a*a*a;
	}
	ll b = n / k;
	ans += b*b*b;
	cout<<ans<<endl;

	return 0;
}
