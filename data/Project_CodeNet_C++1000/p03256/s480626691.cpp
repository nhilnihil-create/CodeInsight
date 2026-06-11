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
  string S;
  cin>>S;
  vector<vector<int> > edge(N);
  int a, b;
  for(int i=0;i<M;++i) {
    cin>>a>>b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  map<int, pair<int, int> > amap;
  int anum, bnum;
  queue<tuple<int, int, int> > que;
  for(int i=0;i<N;++i) {
    anum = 0;
    bnum = 0;
    for(int j=0;j<edge[i].size();++j) {
      if(S[edge[i][j]]=='A') {
        anum++;
      }
      else {
        bnum++;
      }
    }
    if(anum==0 || bnum==0) que.push(make_tuple(i, anum, bnum));
    amap[i] = mp(anum, bnum);
  }
  map<int, int> bmap;
  tuple<int, int, int> state;
  int node;
  while(!que.empty()) {
    state = que.front();que.pop();
    node = get<0>(state);
    if(bmap[node]>0) continue;
    bmap[node] = 1;
    for(int i=0;i<edge[node].size();++i) {
      anum = amap[edge[node][i]].fi;
      bnum = amap[edge[node][i]].se;
      if(S[node]=='A') anum--;
      else bnum--;
      if(anum==0 || bnum==0) {
        if(bmap[edge[node][i]]==0) que.push(make_tuple(edge[node][i], anum, bnum));
      }
      amap[edge[node][i]] = mp(anum, bnum);
    }
  }
  bool can = false;
  for(int i=0;i<N;++i) {
    if(bmap[i]==0) can = true;
  }
  if(can) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

