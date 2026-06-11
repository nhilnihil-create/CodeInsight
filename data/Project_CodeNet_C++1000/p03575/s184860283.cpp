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
  vector<vector<int> > edge(N);
  int a, b;
  for(int i=0;i<M;++i) {
    cin>>a>>b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  int ans = 0;
  queue<int> que;
  int state;
  bool can;
  for(int i=0;i<N;++i) {
    for(int j=0;j<edge[i].size();++j) {
      if(i>edge[i][j]) continue;
      map<int, int> amap;
      que.push(0);
      while(!que.empty()) {
        state = que.front();que.pop();
        if(amap[state]>0) continue;
        amap[state]++;
        for(int k=0;k<edge[state].size();++k) {
          if((state==i && edge[state][k]==edge[i][j]) || (state==edge[i][j] && edge[state][k]==i)) continue;
          if(amap[edge[state][k]]>0) continue;
          que.push(edge[state][k]);
        }
      }
      can = true;
      for(int i=0;i<N;++i) {
        if(amap[i]==0) can = false;
      }
      if(!can) ans++;
    }
  }
  cout<<ans<<endl;
}

