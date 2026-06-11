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
  string N;
  cin >> N;
  int S=N.size(), A, K=0, ans;
  if (N[0]=='1') {
    A=1;
  }
  else if (N[0]=='2') {
    A=2;
  }
  else if (N[0]=='3') {
    A=3;
  }
  else if (N[0]=='4') {
    A=4;
  }
  else if (N[0]=='5') {
    A=5;
  }
  else if (N[0]=='6') {
    A=6;
  }
  else if (N[0]=='7') {
    A=7;
  }
  else if (N[0]=='8') {
    A=8;
  }
  else {
    A=9;
  }
  ans=A+9*(S-1)-1;
  if (S==1) {
    ans=A;
  }
  else {
    for (int i=1; i<S; i++) {
      if (N[i]=='9') {
        K++;
      }
    }
    if (K==S-1) {
      ans=A+9*K;
    }
  }
  cout << ans << endl;
}
