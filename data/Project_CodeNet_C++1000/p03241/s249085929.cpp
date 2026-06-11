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

std::map<long long, long long> prime_factor(long long n) {
  std::map<long long, long long> ret; // ret.first:prime_number, ret.second:count
  for(long long i = 2; i * i <= n; ++i) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1; // if n is prime number.
  return ret;
}

int main() {
  ll N, M;
  cin >> N >> M;

  ll div = N;
  map<ll, ll> primes = prime_factor(M);
  for (const auto prime : primes) {
    if (prime.first > N) {
      div = prime.first;
      break;
    }
  }
  if (div < 10e7) {
    div = N;
    while (M%div != 0) {
      div++;
    }
  }
  ll ans = M/div;
  cout << ans << endl;
  return 0;
}