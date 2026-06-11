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

int main() {
  ll N, M;
  cin>>N>>M;
  vector<vector<int> > edge(N);
  int A, B;
  for(int i=0;i<M;++i) {
    cin>>A>>B;
    A--;
    B--;
    edge[A].push_back(B);
    edge[B].push_back(A);
  }
  map<int, int> amap;
  for(int i=0;i<N;++i) amap[i] = -1;
  queue<pair<int, int> > que;
  pair<int, int> state;
  que.push(mp(0, 0));
  bool nibu = true;
  int node, parity;
  while(!que.empty()) {
    state = que.front();que.pop();
    node = state.fi;
    parity = state.se;
    if(amap[node]>-1) {
      if(amap[node]!=parity) nibu = false;
      continue;
    }
    amap[node] = parity;
    for(int i=0;i<edge[node].size();++i) {
      if(amap[edge[node][i]]>-1) {
        if(amap[edge[node][i]]!=(parity^1)) nibu = false;
        continue;
      }
      que.push(mp(edge[node][i], parity^1));
    }
  }
  if(!nibu) {
    cout<<N*(N-1)/2-M<<endl;
    return 0;
  }
  ll one=0, zero=0;
  for(int i=0;i<N;++i) {
    if(amap[i]==0) zero++;
    else one++;
  }
  cout<<one*zero-M<<endl;
}

