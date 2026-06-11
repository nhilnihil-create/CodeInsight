// #include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <math.h>
#include <algorithm> // std::sort, std::min, std::next_permutation, std::lower_bound
#include <iomanip> // std::setprecision
#include <cmath> // std::ceil
#include <numeric> // std::gcd, std::lcm
#include <limits> // std::numeric_limits<long int>::max()
#include <unordered_map>
#include <map>
#include <cmath> // std::atan2
#include <deque>
#include <queue>

using namespace std;
typedef long long ll;
#define INF 1999999999
#define MODA 1000000007 
#define rep(i,n) for (long long i = 0; i < (n); ++i)

template<typename T>
T convert_rooted_tree(const T &tree, long long root = 0) {
  long long N = tree.size();
  T rooted_tree(N);
  vector<bool> foundflag(N);
  foundflag[root] = true;
  queue<long long> que;
  que.emplace(root);
  while(!que.empty()) {
    auto p = que.front();
    que.pop();
    for(auto &to : tree[p]) {
      if(foundflag[to] == false) {
        foundflag[to] = true;
        que.emplace(to);
        rooted_tree[p].emplace_back(to);
      }
    }
  }
  return rooted_tree;
}

int main() {
  ll N;
  cin >> N;
  vector<ll> u(N), v(N), w(N);
  for(ll i=1; i<N; ++i) cin >> u[i] >> v[i] >> w[i];

  vector<vector<pair<ll, ll> > > tree(N+1);
  for(ll i=1; i<N; ++i) {
    tree[u[i]].emplace_back(make_pair(v[i], w[i]));
    tree[v[i]].emplace_back(make_pair(u[i], w[i]));
  }
  ll root = 1;

  vector<vector<pair<ll, ll> > > rooted_tree(N+1);
  vector<bool> foundflag(N+1);
  foundflag[root] = true;
  queue<long long> que1;
  que1.emplace(root);
  while(!que1.empty()) {
    auto p = que1.front();
    que1.pop();
    for(auto &to : tree[p]) {
      if(foundflag[to.first] == false) {
        foundflag[to.first] = true;
        que1.emplace(to.first);
        rooted_tree[p].push_back(to);
      }
    }
  }

  vector<int> color(N+1);
  color[root] = 0;
  queue<ll> que;
  que.emplace(root);
  while (!que.empty()) {
    auto p = que.front();
    que.pop();
    for (auto &edges : rooted_tree[p]) {
      que.emplace(edges.first);
      if(edges.second%2 == 0) {
        color[edges.first] = color[p];
      } else {
        color[edges.first] = color[p] ^ 1;
      }
    }
  }
      
  for (ll i=1; i<N+1; ++i) {
    cout << color[i] << endl;
  } 
  return 0;
}
