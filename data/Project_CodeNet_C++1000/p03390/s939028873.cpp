#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  
#include <chrono>
#include <random>
#include <time.h>
#include <fstream>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define all(c) begin(c),end(c)
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

#define INF 1e9+7
#define LLINF 1e18+7
#define N 250000
ll MOD=1e9+7;
struct HopcroftKarp {
  vector< vector< int > > graph;
  vector< int > dist, match;
  vector< bool > used, vv;

  HopcroftKarp(int n, int m) : graph(n), match(m, -1), used(n) {}

  void add_edge(int u, int v) {
    graph[u].push_back(v);
  }

  void bfs() {
    dist.assign(graph.size(), -1);
    queue< int > que;
    for(int i = 0; i < graph.size(); i++) {
      if(!used[i]) {
        que.emplace(i);
        dist[i] = 0;
      }
    }

    while(!que.empty()) {
      int a = que.front();
      que.pop();
      for(auto &b : graph[a]) {
        int c = match[b];
        if(c >= 0 && dist[c] == -1) {
          dist[c] = dist[a] + 1;
          que.emplace(c);
        }
      }
    }
  }

  bool dfs(int a) {
    vv[a] = true;
    for(auto &b : graph[a]) {
      int c = match[b];
      if(c < 0 || (!vv[c] && dist[c] == dist[a] + 1 && dfs(c))) {
        match[b] = a;
        used[a] = true;
        return (true);
      }
    }
    return (false);
  }

  int bipartite_matching() {
    int ret = 0;
    while(true) {
      bfs();
      vv.assign(graph.size(), false);
      int flow = 0;
      for(int i = 0; i < graph.size(); i++) {
        if(!used[i] && dfs(i)) ++flow;
      }
      if(flow == 0) return (ret);
      ret += flow;
    }
  }

  void output() {
    for(int i = 0; i < match.size(); i++) {
      if(~match[i]) {
        cout << match[i] << "-" << i << endl;
      }
    }
  }
};


main(){
    int q=in();
    rep(iii,q){
        ll a=in(),b=in();
        if(a==b)cout<<(a-1)*2<<endl;
        else{
            if(a>b)swap(a,b);
            ll ans=a-1;
            ll c;
            ll l=0,r=1e9+1;
            while(l<r-1){
                ll mid=(l+r)/2;
                if(mid*mid<a*b)l=mid;
                else r=mid;
            }
            c=l;
            ll d=c;
            if(c*(d+1ll)<a*b){
                cout<<ans+c+c-a<<endl;
            }
            else{
                cout<<ans+c+c-a-1<<endl;
            }
        }
    }
}
