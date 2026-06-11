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

double N, K;
int NUM;

double p(int a, int key) {
  int res = 1;
  int x = key;
  while(x > 0) {
    if(x & 1) {
      res *= a;
    }
    x >>= 1;
    a *= a;
  }
  return res;
}

int main() {
  cin >> N >> K;
  NUM = floor(log2(K - 0.1)) + 1;
  double ans = 0;
  double par = pow(2, NUM);
  double ch = 0;
  for(int i = 1; i <= N; i++) {
    if(i >= K) {
      ch += par;
      continue;
    }
    int temp = floor(log2((K - 0.1) / i)) + 1;
    ch += pow(2, NUM - temp);
  }
  cout << std::fixed << std::setprecision(11) << ch / (par * N) << endl;
  return 0;
}