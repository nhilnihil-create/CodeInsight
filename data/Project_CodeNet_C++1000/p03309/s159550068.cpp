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
#define all(x) (x).begin(),(x).end()

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i,N) cin >> A[i];
  
  rep(i,N) {
    A[i] -= i+1;
  }
  sort(all(A));
  ll med = A[N/2];
  ll ans = 0;
  rep(i,N) {
    ans += abs(A[i] - med);
  }
  cout << ans << endl;
  return 0;
}
