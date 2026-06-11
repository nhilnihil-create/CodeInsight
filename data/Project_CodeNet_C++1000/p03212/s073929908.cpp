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

ll N;

void next_num (ll num, ll digit, ll& count, bool tflag, bool fflag, bool sflag){
  if (num <= N) {
    if (tflag && fflag && sflag) count++;
    next_num(num + 3*digit, 10*digit, count, true, fflag, sflag);
    next_num(num + 5*digit, 10*digit, count, tflag, true, sflag);
    next_num(num + 7*digit, 10*digit, count, tflag, fflag, true);
  }
}


int main() {
  cin >> N;
  ll count=0;

  next_num (3, 10, count, true, false, false);
  next_num (5, 10, count, false, true, false);
  next_num (7, 10, count, false, false, true);

  cout << count << endl;
  return 0;
}

