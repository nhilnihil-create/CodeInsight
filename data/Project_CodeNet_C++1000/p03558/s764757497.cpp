#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()

#define AMAX 100010
#define DMAX 1000000000000000000

int N;
struct edge{
  int to,cost;
};
vector<edge> G[AMAX];
ll D[AMAX];

void dijkstra(int s){
  priority_queue<P,vector<P>,greater<P>> Q;
  rep(i,N) D[i]=DMAX;
  D[s]=0;
  Q.push(P(0,s));
  while(!Q.empty()){
    P p=Q.top();
    Q.pop();
    int x=p.second;
    if(D[x]<p.first) continue;
    rep(i,G[x].size()){
      edge e=G[x][i];
      if(D[e.to]>D[x]+e.cost){
        D[e.to]=D[x]+e.cost;
        Q.push(P(D[e.to],e.to));
      }
    }
  }
}


int main(){
  cin>>N;
  rep(i,N){
    edge E1={(i+1)%N,1};
    G[i].push_back(E1);
    edge E10={i*10%N,0};
    G[i].push_back(E10);
  }
  dijkstra(1);
  cout<<D[0]+1<<endl;
}

