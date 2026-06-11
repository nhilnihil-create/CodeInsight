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
  vector<vector<ll> > edge(N);
  ll A, B;
  for(ll i=0;i<M;++i) {
    cin>>A>>B;
    A--;
    B--;
    edge[A].push_back(B);
    edge[B].push_back(A);
  }
  queue<pair<ll, ll> > que;
  que.push(mp(0, 0));
  map<pair<ll, ll>, ll> amap;
  pair<ll, ll> state;
  ll node, dist;
  while(!que.empty()) {
    state = que.front();que.pop();
    node = state.fi;
    dist = state.se%2;
    if(amap[mp(node, dist%2)]>0) continue;
    amap[mp(node, dist%2)]++;
    for(ll i=0;i<edge[node].size();++i) {
      if(amap[mp(node, (dist+1)%2)]>0) continue;
      que.push(mp(edge[node][i], (dist+1)%2));
    }
  }
  ll onenum = 0, zeronum = 0, bothnum = 0;
  for(ll i=0;i<N;++i) {
    if(amap[mp(i, 0)]>0 && amap[mp(i, 1)]==0) zeronum++;
    if(amap[mp(i, 1)]>0 && amap[mp(i, 0)]==0) onenum++;
    if(amap[mp(i, 1)]>0 && amap[mp(i, 0)]>0) bothnum++;
  }
  if(bothnum>0) cout<<N*(N-1)/2-M<<endl;
  else cout<<onenum*zeronum-M<<endl;
}
