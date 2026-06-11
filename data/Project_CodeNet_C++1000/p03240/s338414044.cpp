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
#define rep(i,s,e) for (int64_t i=s; i<e; i++)
#define pi 3.14159265358979323846264338327950L
using namespace std;

int main() {
  int N, S, T, U, H;
  cin >> N;
  long int O=0;
  vector<int> x(N);
  vector<int> y(N);
  vector<int> h(N);
  rep(i,0,N) {
    cin >> x[i] >> y[i] >> h[i];
  }
  rep(i,0,N) {
    if (h[i]>0) {
      S=x[i];
      T=y[i];
      U=h[i];
      break;
    }
  }
  rep(X,0,101) {
    rep(Y,0,101) {
      H=U+abs(X-S)+abs(Y-T);
      int K=0;
      rep(i,0,N) {
        if (h[i]==max((H-abs(x[i]-X)-abs(y[i]-Y)),O)) {
          K++;
        }
      }
      if (K==N) {
        cout << X << " " << Y << " " << H << endl;
      }
    }
  }
}