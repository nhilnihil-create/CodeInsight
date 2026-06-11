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
  int H, W;
  cin>>H>>W;
  vector<string> S(H);
  for(int i=0;i<H;++i) cin>>S[i];
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > que;
  tuple<int, int, int> state;
  que.push(make_tuple(1, 0, 0));
  map<pair<int, int>, int> amap;
  int white = 0;
  for(int i=0;i<H;++i) {
    for(int j=0;j<W;++j) {
      if(S[i][j]=='.') white++;
    }
  }
  int x, y, cost;
  while(!que.empty()) {
    state = que.top();que.pop();
    x = get<1>(state);
    y = get<2>(state);
    cost = get<0>(state);
    if(amap[mp(x, y)]>0) continue;
    amap[mp(x, y)] = cost;
    if(x>0 && S[x-1][y]=='.') {
      if(amap[mp(x-1, y)]==0) {
        que.push(make_tuple(cost+1, x-1, y));
      }
    }
    if(x<H-1 && S[x+1][y]=='.') {
      if(amap[mp(x+1, y)]==0) {
        que.push(make_tuple(cost+1, x+1, y));
      }
    }
    if(y>0 && S[x][y-1]=='.') {
      if(amap[mp(x, y-1)]==0) {
        que.push(make_tuple(cost+1, x, y-1));
      }
    }
    if(y<W-1 && S[x][y+1]=='.') {
      if(amap[mp(x, y+1)]==0) {
        que.push(make_tuple(cost+1, x, y+1));
      }
    }
  }
  if(amap[mp(H-1, W-1)]==0) {
    cout<<-1<<endl;
    return 0;
  }
  cout<<white-amap[mp(H-1, W-1)]<<endl;
}

