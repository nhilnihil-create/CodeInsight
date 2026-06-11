#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int K; cin >> K;
  int even = 0; int odd = 0;
  for (int i = 1; i <= K; ++i) {
    if (i%2==0) ++even;
    else ++odd;
  }
  cout << even * odd << endl;
  return 0;
}