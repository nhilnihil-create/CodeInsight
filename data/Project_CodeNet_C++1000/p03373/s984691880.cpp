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
  int64_t A, B, C, X, Y, O=0;
  cin >> A >> B >> C >> X >> Y;
  vector<int64_t> P(100001);
  rep(i,0,100001) {
    P[i]=2*i*C+max((X-i),O)*A+max((Y-i),O)*B;
  }
  sort(P.begin(),P.end());
  cout << P[0] << endl;
}