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
  int H, W;
  cin>>H>>W;
  vector<vector<int> > edge(10);
  int c;
  for(int i=0;i<10;++i) {
    for(int j=0;j<10;++j) {
      cin>>c;
      edge[j].push_back(c);
    }
  }
  map<int, int> amap;
  for(int i=0;i<10;++i) amap[i] = -1;
  pair<int, int> state;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
  que.push(mp(0, 1));
  int node, cost;
  while(!que.empty()) {
    state = que.top();que.pop();
    node = state.se;
    cost = state.fi;
    if(amap[node]>-1) continue;
    amap[node] = cost;
    for(int i=0;i<10;++i) {
      if(amap[i]>-1) continue;
      que.push(mp(cost+edge[node][i], i));
    }
  }
  int ans = 0;
  int A;
  for(int i=0;i<H;++i) {
    for(int j=0;j<W;++j) {
      cin>>A;
      if(A==-1) continue;
      ans += amap[A];
    }
  }
  cout<<ans<<endl;
}

