#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 50;
constexpr double pi=3.14159265358979;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
using namespace std;

bool visited[10005],visited2[10005];
int p,sum;
vector<int>c,d;
vector<vector<int>>g;

void dfs(int v){
    visited[v]=true;
    d[v]=c[p];
    ++p;
    for(auto x:g[v]){
      if(!visited[x]){
        dfs(x);
      }
    }
}

void dfs2(int v){
  visited2[v]=true;
  for(auto x:g[v]){
    if(!visited2[x]){
      sum+=min(d[v],d[x]);
      dfs2(x);
    }
  }
}
void solve(){
  int n;
  cin>>n;
  vector<int>cnt(n);
  c.resize(n);d.resize(n);
  g.resize(n);
  rep(i,n-1){
    int a,b;
    cin>>a>>b;
    --a;--b;
    g[a].pb(b);
    g[b].pb(a);
    cnt[a]++;
    cnt[b]++;
  }
  rep(i,n)cin>>c[i];
  sort(c.rbegin(),c.rend());
  int ans=0,root;
  rep(i,n){
    if(chmax(ans,cnt[i]))root=i;
  }
  d[root]=c.front();
  dfs(root);
  dfs2(root);
  cout<<sum<<"\n";
  rep(i,n){
    if(i)cout<<" ";
    cout<<d[i];
  }
  cout<<"\n";
  return;
}

signed main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	solve();
	return 0;
}
