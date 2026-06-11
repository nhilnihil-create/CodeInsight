#include <bits/stdc++.h>//復習必須
#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
#define P pair<int, int>
ll N ;
void solve() {
  cin >> N;
  if (N == 0) {
    cout << 0 << endl;return;
  }
  string s = "";
  while (N) {
    ll r = N % -2;
    if (r<0) r+=2;
    s += to_string(r);
    N = (N-r) / -2;
  }
  reverse(s.begin(), s.end());
  cout << s << endl;
}
int main () {
    solve() ;

    return 0 ;
}

 
