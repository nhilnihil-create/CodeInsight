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
const ll big=1e18;
const double PI=2*asin(1);

bool DP[200005];

int main() {
  int N;
  cin>>N;
  vector<vector<int> > edge(N);
  int a, b;
  for(int i=0;i<N-1;++i) {
    cin>>a>>b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  queue<pair<int, int> > que;
  que.push(mp(0, 0));
  map<int, int> amap;
  for(int i=0;i<N;++i) amap[i] = -1;
  pair<int, int> state;
  while(!que.empty()) {
    state = que.front();que.pop();
    if(amap[state.fi]>-1) continue;
    amap[state.fi] = state.se;
    for(int i=0;i<edge[state.fi].size();++i) {
      if(amap[edge[state.fi][i]]>-1) continue;
      que.push(mp(edge[state.fi][i], state.se+1));
    }
  }
  int dist = 0;
  int node = 0;
  for(int i=0;i<N;++i) {
    if(dist<amap[i]) {
      dist = amap[i];
      node = i;
    }
  }
  que.push(mp(node, 0));
  for(int i=0;i<N;++i) amap[i] = -1;
  while(!que.empty()) {
    state = que.front();que.pop();
    if(amap[state.fi]>-1) continue;
    amap[state.fi] = state.se;
    for(int i=0;i<edge[state.fi].size();++i) {
      if(amap[edge[state.fi][i]]>-1) continue;
      que.push(mp(edge[state.fi][i], state.se+1));
    }
  }
  int distmax = 0;
  for(int i=0;i<N;++i) distmax = max(distmax, amap[i]);
  DP[0] = true;
  DP[1] = false;
  for(int i=2;i<=distmax;++i) {
    if(DP[i-2] && DP[i-1]) DP[i] = false;
    else DP[i] = true;
  }
  if(DP[distmax]) cout<<"First"<<endl;
  else cout<<"Second"<<endl;
}

