#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define lli long long int
#define uli unsigned long long int
#define INF 999999999999999999
#define rep(i,m,n) for(lli i = m;i < n;i++)
#define rrep(i,m,n) for(lli i=m-1;i>=n;i--)
#define pb(n) push_back(n)
#define UE(N) N.erase(unique(N.begin(),N.end()),N.end());
#define Sort(n) sort(n.begin(), n.end())
#define Rev(n) reverse(n.begin(),n.end())
#define Out(S) cout << S << endl
#define NeOut(S) cout << S
#define HpOut(S) cout << setprecision(25) << S << endl
#define Vec(K,L,N,S) vector<L> K(N,S)
#define DV(K,L,N,M,S) vector<vector<L>> K(N,vector<L>(M,S))
#define TV(K,L,N,M,R,S) vector<vector<vector<L>>> K(N,vector<vector<L>>(M,vector<L>(R,S)))
#define pint pair<lli,lli>
#define paf(L,R) pair<L,R>
#define mod 1000000007
#define MAX 10000000
#define ALL(a)  a.begin(),a.end()
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
struct UnionFind {
  vector< int > data;
 
  UnionFind(int sz) {
    data.assign(sz, -1);
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  lli A,B,C,D,E,F,N,M,K,L,X,Y,Z,H,W,sum=0,num=0,flag=0;string S,T;
  cin >> N >> M;
  deque<lli>que;
  UnionFind uf(N);
  Vec(G,pint,M,pint(0,0));
  rep(i,0,M)cin >> G[i].first >> G[i].second;
  Rev(G);
  num=N*(N-1)/2;
  que.push_front(num-0);
  rep(i,0,M-1){
    sum=0;
    if(uf.find(G[i].first-1)!=uf.find(G[i].second-1))num-=uf.size(G[i].first-1)*uf.size(G[i].second-1);
    uf.unite(G[i].first-1,G[i].second-1);
    que.push_front(num);
  }
  while(!que.empty()){
    auto v=que.front();que.pop_front();
    Out(v);
  }
}