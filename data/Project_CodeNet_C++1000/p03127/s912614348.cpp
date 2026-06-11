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
  int64_t N, ans;
  cin >> N;
  vector<int64_t> A(N);
  for (int64_t i=0; i<N; i++) {
    cin >> A[i];
  }
  ans=A[0];
  for (int64_t i=0; i<N; i++) {
    ans=gcd(ans,A[i]);
  }
  cout << ans << endl;
}