#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 


////////////////////////////////////////////////////////////////////
template<typename T>
struct edge {
  int to, from;T cost;
  edge(int to) : from(-1), to(to), cost(-1) {}
  edge(int to, T cost) : from(-1), to(to), cost(cost) {}
  edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};
template<typename T>
using edges = vector<edge<T>>;
template<typename T>
using graph = vector<edges<T>>;
template<typename T>
using matrix = vector<vector<T>>;

template<typename T>
bool compByCost(const edge<T>& left, const edge<T>& right){
  return left.cost < right.cost; 
}

template<typename T>
vector<vector<T>> warshall(matrix<T> &g){
  vector<vector<T>> dist(g.size());
  rep(i,g.size()){
    dist[i].resize(g.size());
    rep(j,g.size())dist[i][j] = (i == j ? 0 : g[i][j]);
  }
  rep(k,g.size()){
    rep(i,g.size()){
      rep(j,g.size()){
        if(dist[i][k] == INF || dist[k][j] == INF)continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  return dist;
}

#define warshall warshall<int>// matの初期化でINFを詰めておく



////////////////////////////////////////////////////////////////////

int n,c;priority_queue<P, vector<P>, greater<P>> stq[35];
stack<P> st[35];priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> que;
signed main(){
  cin>>n>>c;
  rep(i,n){
    int s,t,cc;cin>>s>>t>>cc;cc--;
    stq[cc].push(P(s,t));
  }
  rep(i,n){
    rep(cc,c){
      while(!stq[cc].empty()){
        int s = stq[cc].top().first,t = stq[cc].top().second;stq[cc].pop();
        if(st[cc].empty() || st[cc].top().second != s){
          st[cc].push(P(s,t));
        }else{
          P p = st[cc].top();st[cc].pop();
          st[cc].push(P(p.first, t));
        }
      }
    }
  }
  rep(i,c){
    while(!st[i].empty()){
      P p = st[i].top();st[i].pop();
      que.push(P((double)p.first-0.5, 1));
      que.push(P(p.second, 0));
    }
  }
  int ans = 0, cnt = 0, s = -1, t = -1;
  while(!que.empty()){
    P p = que.top();que.pop();
    if(p.second){
      cnt++;
    }else{
      cnt--;
    }
    chmax(ans, cnt);
  }
  cout << ans << endl;
}
