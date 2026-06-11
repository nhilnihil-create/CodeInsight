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
  vector<pair<int, int> > arr(N);
  int anum, bnum;
  queue<int> que;
  for(int i=0;i<N;++i) {
    anum = 0;
    bnum = 0;
    for(int j=0;j<edge[i].size();++j) {
      if(S[edge[i][j]]=='A') anum++;
      else bnum++;
    }
    arr[i] = mp(anum, bnum);
    if(anum==0 || bnum==0) que.push(i);
  }
  int state;
  pair<int, int> nodes;
  map<int, int> amap;
  while(!que.empty()) {
    state = que.front();que.pop();
    if(amap[state]>0) continue;
    amap[state]++;
    for(int i=0;i<edge[state].size();++i) {
      anum = arr[edge[state][i]].fi;
      bnum = arr[edge[state][i]].se;
      if(S[state]=='A') anum--;
      else bnum--;
      arr[edge[state][i]] = mp(anum, bnum);
      if(anum==0 || bnum==0) que.push(edge[state][i]);
    }
  }
  bool can = false;
  for(int i=0;i<N;++i) {
    if(arr[i].fi>0 && arr[i].se>0) can = true;
  }
  if(can) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
