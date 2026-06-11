#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, M;
  cin>>N>>M;
  vector<vector<int> > edge(N), edge1(N);
  int A, B;
  for(int i=0;i<N+M-1;++i) {
    cin>>A>>B;
    A--;
    B--;
    edge[A].push_back(B);
    edge1[B].push_back(A);
  }
  int parent;
  for(int i=0;i<N;++i) {
    if(edge1[i].size()==0) parent = i;
  }
  int dist[N];
  for(int i=0;i<N;++i) dist[i] = -1;
  queue<pair<int, int> > que;
  que.push(mp(parent, 0));
  pair<int, int> state;
  int node, tmpdist;
  int edgenum[N];
  for(int i=0;i<N;++i) edgenum[i] = 0;
  while(!que.empty()) {
    state = que.front();que.pop();
    node = state.fi;
    tmpdist = state.se;
    if(dist[node]>=tmpdist) continue;
    dist[node] = tmpdist;
    for(int i=0;i<edge[node].size();++i) {
      edgenum[edge[node][i]]++;
      if(edgenum[edge[node][i]]<edge1[edge[node][i]].size()) continue;
      que.push(mp(edge[node][i], tmpdist+1));
    }
  }
  que.push(mp(parent, 0));
  int parents[N];
  parents[parent] = 0;
  while(!que.empty()) {
    state = que.front();que.pop();
    node = state.fi;
    tmpdist = state.se;
    for(int i=0;i<edge[node].size();++i) {
      if(dist[edge[node][i]]!=tmpdist+1) continue;
      parents[edge[node][i]] = node+1;
      que.push(mp(edge[node][i], tmpdist+1));
    }
  }
  for(int i=0;i<N;++i) cout<<parents[i]<<endl;
}

