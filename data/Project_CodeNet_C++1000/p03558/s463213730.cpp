#include <stdio.h>
#include <vector>
#include <functional>
#include <queue>
#include <iostream>
using namespace std;
const int MAX_V=100000;
const int INF=1000000000;
int K;
struct edge {int to, cost;};
typedef pair<int,int> P;
vector<edge> G[MAX_V];
int d[MAX_V];
void dijkstra(int s){
  priority_queue<P,vector<P>,greater<P> >que;
  fill(d,d+K,INF);
  d[s]=1;
  que.push(P(1,s));
 
  while(!que.empty()){
    P p=que.top();
    que.pop();
    int v=p.second;
    if(d[v] < p.first)continue;
    for(int i=0;i < G[v].size();i++){
      edge e=G[v][i];
      if(d[e.to] > d[v]+e.cost){
	d[e.to] = d[v] + e.cost;
	que.push(P(d[e.to],e.to));
      }
    }
  }
}

int main(){
  cin >> K;
  for(int i=0;i<K;i++){
    edge e;
    e.to=(i*10)%K;
    e.cost=0;
    G[i].push_back(e);
    e.to=(i+1)%K;
    e.cost=1;
    G[i].push_back(e);
  }

  dijkstra(1);
  cout << d[0] << endl;
  return 0;
}
