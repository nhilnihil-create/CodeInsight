#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using P = pair<long long, long long>;

long long N;
vector<long long> A, B, C;

int main() {
  cin >> N;
  rep(i, N) {
    int x;
    cin >> x;
    A.push_back(x);
  }
  rep(i, N) {
    int x;
    cin >> x;
    B.push_back(x);
  }
  rep(i, N) {
    int x;
    cin >> x;
    C.push_back(x);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  long long ans = 0;
  rep(i, N) {
    long long b = B[i];
    long long a, c;
    a = lower_bound(A.begin(), A.end(), b) - A.begin();
    c = upper_bound(C.begin(), C.end(), b) - C.begin();
    ans += a * (C.size()-c);
  }
  cout << ans << endl;
  return 0;
}