// includes {{{
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<random>
#include<cassert>
// }}}
// #include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
string s;

int cnt1[1123456];

int range1(int l, int r) {
  int res = cnt1[r];
  if(l - 1 >= 0) res -= cnt1[l-1];
  return res;
}

int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  cin >> n >> s;
  for(int i = 0; i < n; i++) {
    cnt1[i] = s[i] == 'M';
    if(i) cnt1[i] += cnt1[i-1];
  }
  int q;
  cin >> q;

  int k;
  // DMC
  while(q--) {
    cin >> k;
    deque<int> v;
    ll ans = 0;
    ll now = 0;
    for(int i = 0; i < n; i++) {
      while(v.size() && v.front() <= i - k) now -= range1(v.front(), i - 1), v.pop_front();
      if(s[i] == 'D') {
        v.emplace_back(i);
      }
      if(s[i] == 'M') {
        now += v.size();
      }
      if(s[i] == 'C') {
        ans += now;
      }
    }
    cout << ans << "\n";
  }
  
  return 0;
}
