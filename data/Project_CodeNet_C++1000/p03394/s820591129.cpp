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
#define PI 3.14159265359
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



int N;
vector<int> ans;

int main () {
  cin >> N;

  if (N == 3) {
    ans.push_back(2);
    ans.push_back(5);
    ans.push_back(63);
  } else if (N <= 15002) {
    ans.push_back(3);
    ans.push_back(9);

    int m = N - 2;
    int k = m / 3;
    int amari = m % 3;

    rep(i, k) {
      ans.push_back(i * 6 - 4);
      ans.push_back(i * 6 - 2);
      ans.push_back(i * 6);
    }

    if (amari == 1) {
      ans.push_back((k+1)*6);
    } else if (amari == 2) {
      ans.push_back((k+1)*6 - 4);
      ans.push_back((k+1)*6 - 2);
    }
  } else {
    ans.push_back(3);
    ans.push_back(9);

    if (N % 2 == 0) {
      rep(i, 15000) {
        ans.push_back(i * 2);
      }
    } else {
      rep(i, 14999) {
        ans.push_back(i * 2);
      } 
    }

    int noko = N - ans.size();

    rep(i, noko) {
      ans.push_back(i * 6 + 9);
    }
  }

  printv(ans);
}