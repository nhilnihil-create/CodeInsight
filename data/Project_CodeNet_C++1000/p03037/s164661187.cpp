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
  int N, M, l=0, r=100000;
  cin >> N >> M;
  vector<int> L(M);
  vector<int> R(M);
  for (int i=0; i<M; i++) {
    cin >> L[i] >> R[i];
    l=max(l,L[i]);
    r=min(r,R[i]);
  }
  cout << max((r-l+1),0) << endl;
}