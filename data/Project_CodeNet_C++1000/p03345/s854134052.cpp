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
  int64_t A, B, C, K;
  cin >> A >> B >> C >> K;
  if (K%2==0) {
    cout << A-B << endl;
  }
  else {
    cout << B-A << endl;
  }
}