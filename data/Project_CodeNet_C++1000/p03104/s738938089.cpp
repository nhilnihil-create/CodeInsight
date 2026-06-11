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
T powint (const T& x, const T& y) {
  T ret = 1;
  for(T i=0; i<y; ++i) ret *= x;
  return ret;
}

int main() {
  ll A, B;
  cin >> A >> B;

  vector<ll> numflipsB;
  for (ll i=0; (B >> i) != 0; ++i) {
    ll digit = powint((ll)2, i);
    ll rest = (B+1) % (2 * digit);
    ll blink = (B+1) - rest;
    numflipsB.push_back(blink / 2);
    //cerr << blink <<" "<< rest <<" "<< digit << endl;
    if (rest > digit) numflipsB[i] += rest - digit;
  }

  A = A - 1;
  vector<ll> numflipsA;
  for (ll i=0; (B >> i) != 0; ++i) {
    if (A >> i == 0) {
      numflipsA.push_back(0);
      continue;
    }
    ll digit = powint((ll)2, i);
    ll rest = (A+1) % (2 * digit);
    ll blink = (A+1) - rest;
    numflipsA.push_back(blink / 2);
    //cerr << blink <<" "<< rest <<" "<< digit << endl;
    if (rest > digit) numflipsA[i] += rest - digit;
  }
  
  long long ans = 0;
  for (ll i = 0; i < numflipsB.size(); ++i) {
    cerr << numflipsB[i] <<" "<< numflipsA[i] << endl;
    if ((numflipsB[i] - numflipsA[i]) % 2 == 1) ans += (ll)1 << i;
  }
  cout << ans << endl; 
  return 0;
}
