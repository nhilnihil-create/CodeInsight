#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define pi 3.14159265358979323846264338327950L
using namespace std;

int main() {
  int64_t N, X, D;
  cin >> N >> X;
  vector<int64_t> x(N);
  vector<int64_t> y(N);
  for (int64_t i=0; i<N; i++) {
    cin >> x[i];
    y[i]=abs(X-x[i]);
  }
  sort(y.begin(),y.end());
  reverse(y.begin(),y.end());
  D=y[0];
  for (int64_t i=0; i<N; i++) {
    if (y[i]!=0) {
      D=gcd(D,y[i]);
    }
  }
  cout << D << endl;
}