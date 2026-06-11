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
  int64_t K, ans;
  cin >> S >> K;
  for (int64_t i=0; i<K; i++) {
    if (S[i]=='1') {
      ans=1;
    }
    else if (S[i]=='2') {
      ans=2;
      break;
    }
    else if (S[i]=='3') {
      ans=3;
      break;
    }
    else if (S[i]=='4') {
      ans=4;
      break;
    }
    else if (S[i]=='5') {
      ans=5;
      break;
    }
    else if (S[i]=='6') {
      ans=6;
      break;
    }
    else if (S[i]=='7') {
      ans=7;
      break;
    }
    else if (S[i]=='8') {
      ans=8;
      break;
    }
    else if (S[i]=='9') {
      ans=9;
      break;
    }
  }
  cout << ans << endl;
}