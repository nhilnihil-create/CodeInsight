#include<bits/stdc++.h>
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

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using ll = long long;
using P = pair<int, int>;
using MATRIX = vector< vector<ll> >;
template <class T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <class T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}

int main() {
  string s;
  cin >> s;
  int a, b;
  a = atoi(s.substr(0, 2).c_str());
  b = atoi(s.substr(2, 2).c_str());
  if(a >= 1 && a <= 12) {
    if(b >= 1 && b <= 12) {
      cout << "AMBIGUOUS" << endl;
    } else {
      cout << "MMYY" << endl;
    }
  } else {
    if(b >= 1 && b <= 12) {
      cout << "YYMM" << endl;
    } else {
      cout << "NA" << endl;
    }
  }
  return 0;
}