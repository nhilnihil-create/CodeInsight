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

int n,t[110],v[110],s[110];
signed main(){
  cin>>n;rep(i,n)cin>>t[i];rep(i,n)cin>>v[i];
  rep(i,110)s[i] = INF;
  s[0] = s[n] = 0;
  rep(i,n+1){
    chmin(s[i], v[i]);
    repd(j,i+1,n+1){
      chmin(s[j], v[j-1]);
      chmin(s[j], s[j-1]+t[j-1]);
    }
    for(int j = i-1;j >= 0;j--){
      chmin(s[j], v[j]);
      chmin(s[j], s[j+1]+t[j]);
    }
  }
  double ret = 0;
  rep(i,n){
    double ans = 0;
    double a = v[i] - s[i], b = v[i] - s[i+1], c = a+b;
    if(c <= (double)t[i]){
      ans += a*a*0.5 + a*(double)s[i];
      ans += (double)(t[i] - a - b)*(double)v[i];
      ans += b*b*0.5 + b*(double)s[i+1];
    }else{
      double top = 0.5*(double)(t[i] + s[i] + s[i+1]);
      ans += 0.5*(double)(top-s[i])*(double)(top - s[i]);
      ans += 0.5*(double)(top-s[i+1])*(double)(top - s[i+1]);
      ans += (double)(top-s[i])*(double)s[i];
      ans += (double)(top-s[i+1])*(double)s[i+1];
    }
    ret += ans;
  }
  cout << fixed << ret << endl;
}
