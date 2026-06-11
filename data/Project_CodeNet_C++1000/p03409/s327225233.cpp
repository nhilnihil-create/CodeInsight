#include <bits/stdc++.h>
using namespace std;

int N;int INF=1000007;

struct edge{
  int to,cap,rev;
  edge (int t,int c,int r) {
    to=t;cap=c;rev=r;
  }
};

void add_edge(int a,int b,int cap,vector<vector<edge>> &g) {
  g[a].push_back(edge(b,cap,g[b].size()));
  g[b].push_back(edge(a,0,g[a].size()-1));
}

int dfs(int v,int t,int f,vector<vector<edge>> &g,vector<int> &used) {
  if (v==t) return f;
  used[v]=1;
  for (edge &e:g[v]) {
    if (used[e.to]==0 && e.cap>0) {
      int d=dfs(e.to,t,min(f,e.cap),g,used);
      if (d>0) {
        e.cap-=d;
        g[e.to][e.rev].cap+=d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s,int t,vector<vector<edge>> g) {
  int flow=0;
  while (true) {
    vector<int> used(g.size(),0);
    int f=dfs(s,t,INF,g,used);
    if (f==0) return flow;
    flow+=f;
  }
}

int main() {
  cin >> N;int A[N][2];int B[N][2];
  for (int i=0;i<N;i++) {
    cin >> A[i][0] >> A[i][1];
  }
  for (int i=0;i<N;i++) {
    cin >> B[i][0] >> B[i][1];
  }
  vector<vector<edge>> g(2*N+2);
  for (int i=0;i<N;i++) {
    add_edge(0,i+1,1,g);
  }
  for (int i=0;i<N;i++) {
    for (int j=0;j<N;j++) {
      if (A[i][0]<B[j][0] && A[i][1]<B[j][1]) {
        add_edge(i+1,j+N+1,1,g);
      }
    }
  }
  for (int i=0;i<N;i++) {
    add_edge(i+N+1,2*N+1,1,g);
  }
  cout << max_flow(0,2*N+1,g) << endl;
}