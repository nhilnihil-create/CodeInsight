#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#define MAX 200003
#define MOD 1000000007

typedef int FLOW;
vector<int> level;
#define INF 1000
#define V_MAX 300

struct Edge{
  int rev,from,to;
  FLOW cap,icap;
  Edge(int f,int t,FLOW c){
    from=f;
    to=t;
    cap=c;
    icap=c;
  }
};

struct Graph{
  int V;
  vector<vector<Edge>> list;
  Graph(int n){
    V=n;
    list.resize(V,vector<Edge>(V,Edge(0,0,-1)));
  }
  int size(){
    return V;
  }
  void push_back(int f,int t,FLOW c){
    list.at(f).at(t)=Edge(f,t,c);
    list.at(t).at(f)=Edge(t,f,0);
  }
  Edge& redge(Edge e){
    return list.at(e.to).at(e.from);
  }
};


void dibfs(Graph &G,int s){
  int N=G.size();
  for(int i=0;i<N;i++){
    level.at(i)=-1;
  }
  level.at(s)=0;
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int v=q.front();
    for(auto e:G.list.at(v)){
      if(level.at(e.to)<0&&e.cap>0){
        level.at(e.to)=level.at(v)+1;
        q.push(e.to);
      }
    }
    q.pop();
  }
}

FLOW didfs(Graph &G,int v,int t,FLOW f){
  if(v==t){
    return f;
  }
  for(auto &e:G.list.at(v)){
    Edge &re=G.redge(e);
    if(level[v]<level[e.to]&&e.cap>0){
      FLOW d=didfs(G,e.to,t,min(f,e.cap));
      if(d>0){
        e.cap-=d;
        re.cap+=d;
        return d;
      }
    }
  }
  return 0;
}

FLOW Dinic(Graph &G,int s,int t){
  level.resize(G.size());
  FLOW res=0;
  while(true){
    dibfs(G,s);
    if(level.at(t)==-1){
      return res;
    }
    FLOW flow;
    while((flow=didfs(G,s,t,INF))>0){
      res+=flow;
    }
  }
}

int main(){
  int N;
  cin>>N;
  vector<int> a(N),b(N),c(N),d(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i)>>b.at(i);
  }
  for(int i=0;i<N;i++){
    cin>>c.at(i)>>d.at(i);
  }

  Graph G(2*N+2);
  int S=2*N;
  int T=2*N+1;
  for(int i=0;i<N;i++){
    G.push_back(S,i,1);
    G.push_back(i+N,T,1);
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(a.at(i)<c.at(j)&&b.at(i)<d.at(j)){
        G.push_back(i,N+j,1);
      }
    }
  }

  cout<<Dinic(G,S,T)<<endl;
}
