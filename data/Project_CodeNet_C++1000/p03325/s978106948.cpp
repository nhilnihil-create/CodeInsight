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
  int64_t N, ans=0;
  cin >> N;
  vector<int64_t> a(N);
  vector<int64_t> b(N);
  for (int64_t i=0; i<N; i++) {
    cin >> a[i];
    b[i]=0;
  }
  for (int64_t i=0; i<N; i++) {
    for (int64_t j=1; j<31; j++) {
      if (a[i]%2==0) {
        a[i]=a[i]/2;
        b[i]++;
      }
      else {
        break;
      }
    }
    ans=ans+b[i];
  }
  cout << ans << endl;
}