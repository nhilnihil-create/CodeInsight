#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define Rep(i, n) for(int i=0;i<n;++i)
#define rep(i, n) for(int i=1;i<=n;++i)
#define ll long long int
#define INF 1e9
#define LINF 1e18
#define MOD 1000000007
#define eps 1e-10
#define All(a) (a).begin(), (a).end()

using namespace std;
using P = pair<ll, ll>;
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

/**
 * Usage:
 * 
 * G[from].push_back(Edge(to, weight));
 * using Graph = vector<vector<Edge>>;
 * 
 */ 
struct Edge {
  int to;     
  ll weight; 
  Edge(int t, ll w) : to(t), weight(w) { }
};

/**
 * Usage:
 * 
 * chmin(old, new);
 * chmax(old, new);
 * 
 */ 
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

template<typename T>
void printv(vector<T>& v) {
  if (v.size() == 0) {
    cout << "\n";
    return;
  }

  Rep(i, v.size()) {
    cout << v[i] << ((i + 1 < v.size()) ? ' ' : '\n');
  }
}



ll N, K;
ll a[1100];
ll b[1100];
ll c[1100];
ll num[50];

int main () {
  cin >> N >> K;
  ll sum = 0;
  rep(i, N) {
    ll tmp;
    cin >> tmp;
    a[i] = tmp;
    sum += tmp;
  }

  rep(i, N) {
    b[i] = b[i-1] + a[i];
  }
  for (int i=N;i>=1;--i) {
    c[i] = c[i+1] + a[i];
  }

  vector<ll> v;

  for (int k=0;k<N;++k) {
    for (int l=N+1;l>k+1;--l) {
      v.push_back(sum-b[k]-c[l]);
    }
  }

  //printv(v);

  int n = v.size();
  vector<bool> ok;
  ok.assign(n, true);

  //for (auto p: mp) {
  //  cout << p.first << " " << p.second << "\n";
  //}

  ll ans = 0;

  for (ll s=60;s>=0;--s) {
    int ct = 0;

    Rep(i, n) {
      bitset<59> bt(v[i]);

      if (bt[s] && ok[i]) {
        ct++;
      } 
    }

    if (ct >= K) {
      ans += (1LL << s);

      Rep(i, n) {
        bitset<59> bt(v[i]);
        if (!bt[s] && ok[i]) ok[i] = false;
      }
    }
  }

  cout << ans << "\n";

}
