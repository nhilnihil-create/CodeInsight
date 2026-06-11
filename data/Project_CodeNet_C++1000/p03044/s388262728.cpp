#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <utility>
#include <cassert>
using namespace std;
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main(){
  ll n,m,k,i,j,result=0,u,v,w;
  queue<pair<ll,ll> > que;
  vector<pair<ll,ll> > tree[100010];
  cin >> n;
  vector<ll> dist(n,-1);
  rep(i,n-1){
    cin >> u >> v >> w;
    u--;
    v--;
    tree[u].push_back(make_pair(v,w));
    tree[v].push_back(make_pair(u,w));
  }
  que.push(make_pair(0,0));
  dist[0] = 0;
  while(!que.empty()){
    auto p = que.front();
    que.pop();
    for(auto q : tree[p.first]){
      if(dist[q.first]!=-1) continue;
      que.push(make_pair(q.first,p.second+q.second));
      dist[q.first] = p.second+q.second;
    }
  }
  rep(i,n){
    cout << (dist[i]%2==0 ? 0 : 1) << endl;
  }
  return 0;
}