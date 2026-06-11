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
  ll N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<ll> l(Q), r(Q);
  rep(i, Q) cin >> l[i] >> r[i];

  vector<ll> ACcount(N, 0);
  for (ll i = 1; i < N; ++i) {
    if(S[i-1] == 'A' && S[i] == 'C') {
      ACcount[i] = ACcount[i-1] + 1;
    }
    else {
      ACcount[i] = ACcount[i-1];
    }
  }  
  rep(i, Q) {
    ll count = 0;
    count = ACcount[r[i]-1] - ACcount[l[i]-1];
    cout << count << endl;
  }
  return 0;
}