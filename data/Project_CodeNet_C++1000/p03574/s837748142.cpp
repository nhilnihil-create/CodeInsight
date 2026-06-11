#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower, islower
#include <stdio.h>

//#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long; using ld = long double;
using P = pair<int, int>;

int main() {
  int dh[] = {1,0,-1, 0,1,-1,-1, 1};
  int dw[] = {0,1, 0,-1,1, 1,-1,-1};
  int H,W;
  cin >> H >> W;
  string a[H];
  rep(i,H)cin >> a[i];
 
  rep(i,H)rep(j,W) {
    if(a[i][j] == '#') continue;
    int num = 0;
    rep(k,8) {
      int ni = i+dh[k];
      int nj = j+dw[k];
      if(ni >= H || ni< 0) continue;
      if(nj >= W || nj < 0) continue;
      if(a[ni][nj] == '#') num++;
    }
    a[i][j] = char(num + '0');
  }
   rep(i,H) cout << a[i] << endl;
}