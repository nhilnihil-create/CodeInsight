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
  pair<int, int> state;
  map<int, int> amap;
  for(int i=0;i<N;++i) amap[i] = -1;
  amap[0] = 0;
  while(!que.empty()) {
    state = que.front();que.pop();
    for(int i=0;i<edge[state.fi].size();++i) {
      if(amap[edge[state.fi][i]]>-1) continue;
      que.push(mp(edge[state.fi][i], state.se+1));
      amap[edge[state.fi][i]] = state.se+1;
    }
  }
  int ans = 0;
  int node = 0;
  for(int i=0;i<N;++i) {
    if(ans<amap[i]) {
      ans = amap[i];
      node = i;
    }
  }
  que.push(mp(node, 0));
  for(int i=0;i<N;++i) amap[i] = -1;
  amap[node] = 0;
  while(!que.empty()) {
    state = que.front();que.pop();
    for(int i=0;i<edge[state.fi].size();++i) {
      if(amap[edge[state.fi][i]]>-1) continue;
      que.push(mp(edge[state.fi][i], state.se+1));
      amap[edge[state.fi][i]] = state.se+1;
    }
  }
  for(int i=0;i<N;++i) {
    ans = max(ans, amap[i]);
  }
  ans++;
  if(ans%3==2) cout<<"Second"<<endl;
  else cout<<"First"<<endl;
}

