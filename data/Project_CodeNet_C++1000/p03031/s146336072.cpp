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

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> k(M);
  vector<vector<ll> > s(M); 
  rep(i, M) {
    cin >> k[i];
    rep(j, k[i]) {
      ll tmp;
      cin >> tmp;
      s[i].push_back(tmp);
    }
  }
  vector<int> p(M);
  rep (i, M) cin >> p[i];

  ll ans = 0;
  for (ll bit = 0; bit < (1<<N); ++bit) {
    ll bulbcount = 0;
    rep (i, M) {
      ll oncount = 0;
      for (const auto sj : s[i]) {
        if ((bit>>(sj-1))&1 != 0) oncount++;
      }
      if (oncount%2 == p[i]) bulbcount++;
      cerr << i <<" "<< bit <<" "<< oncount <<" "<< bulbcount << endl;
    }
    if (bulbcount == M) ans++;
  }
  cout << ans << endl;
  return 0;
}
