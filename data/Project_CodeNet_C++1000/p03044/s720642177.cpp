#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using ll = long long;
using P = pair<long long, long long>;
using MATRIX = vector< vector<ll> >;
template <class T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <class T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}

long long dist[100000];
long long visited[100000] = {0};

int main() {
  long long N;
  cin >> N;
  vector<P> e[100000];
  rep(i, N-1) {
    long long u, v, w;
    cin >> u >> v >> w;
    u--;v--;
    e[u].push_back({w, v});
    e[v].push_back({w, u});
  }

  dist[0] = 0;
  queue<long long> que;
  que.push(0);
  while(que.size()) {
    long long x = que.front();
    que.pop();
    visited[x] = 1;
    rep(i, e[x].size()) {
      P p = e[x][i];
      long long w = p.first;
      long long to = p.second;
      if(visited[to] != 1) {
        dist[to] = (dist[x] + w) % 2;
        que.push(to);
      }
    }
  }
  rep(i, N) {
    cout << dist[i] << endl;
  }
  return 0;
}