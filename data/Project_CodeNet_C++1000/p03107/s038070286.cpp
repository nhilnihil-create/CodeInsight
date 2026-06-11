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
  string S;
  cin >> S;
  int N=S.size(), R=0, B=0, ans;
  for (int i=0; i<N; i++) {
    if (S[i]=='0') {
      R++;
    }
    else {
      B++;
    }
  }
  ans=2*min(R,B);
  cout << ans << endl;
}