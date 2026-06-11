#include <bits/stdc++.h>

using namespace std;

const int INF=1e9;

typedef pair<int,int> P;

priority_queue<P, vector<P>, greater<P> > M;

vector<P> edge[200005];

int N[100005];
int K;

void dijkstra(){

while(!M.empty()){

P q=M.top(); M.pop(); 

int cst=q.first; int num=q.second; 

for(int i=0; i<edge[num].size(); i++){

  int node=edge[num][i].first;
  int cost=edge[num][i].second;

  if(N[node]>cst+cost){
    N[node]=cst+cost;
    M.push(P(N[node],node));
  }

}

}

return;

}

int main() {

cin>>K;

for(int i=0; i<K; i++){
  N[i]=INF;
  if(i<K-1) edge[i].push_back(P(i+1,1));
  else edge[i].push_back(P(0,1));
  int to=(i*10)%K;
  edge[i].push_back(P(to,0));
}


M.push(P(0,1)); N[1]=0;

dijkstra();

cout<<N[0]+1<<endl;

}
