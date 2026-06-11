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
  std::map<long long, long long> ret;
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
  ll N;
  cin >> N;

  map<ll, ll> primes;
  for (ll i=1; i<=N; ++i) {
    map<ll, ll> p_i = prime_factor(i);
    for (const auto p : p_i) {
      primes[p.first] += p.second;
    }
  }
  ll five_count = 0;
  ll three_count = 0;
  ll fifteen_count = 0;
  ll twentyfive_count = 0;
  ll seventyfive_count = 0;
  for (const auto p : primes) {
    // cerr << p.second << endl;
    if (p.second >= 4) {
      five_count++;
    }
    if (p.second >= 2) {
      three_count++;
    }
    if (p.second >=14 ) {
      fifteen_count++;
    }
    if (p.second >=24 ) {
      twentyfive_count++;
    }
    if (p.second >=74 ) {
      seventyfive_count++;
    }
  }
  ll ans = 0;
  if (five_count < 2 || three_count < 3) {
    cout << ans << endl;
    return 0;
  }
  ll five_five_three = 0;
  five_five_three = five_count * (five_count-1) / 2;
  five_five_three *= three_count -2;
  ans += five_five_three;
  ll fifteen_five = fifteen_count * (five_count-1);
  ans += fifteen_five;
  ll twentyfive_three = twentyfive_count * (three_count-1);
  ans += twentyfive_three;
  ll seventyfive = seventyfive_count;
  ans += seventyfive;
  cout << ans << endl;
  return 0;
}
