#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int X;
  cin >> X;
  int ma = 0;
  int co = 0;
  rep(i, 35) {
    if(X >= (i+1)*(i+1)) {
      co = (i+1)*(i+1);
      ma = max(ma, co);
    }
  }
  rep(i, 10) {
    if(X >= (i+1)*(i+1)*(i+1)) {
      co = (i+1)*(i+1)*(i+1);
      ma = max(ma, co);
    }
  }
  rep(i, 6) {
    if(X >= (i+1)*(i+1)*(i+1)*(i+1)) {
      co = (i+1)*(i+1)*(i+1)*(i+1);
      ma = max(ma, co);
    }
  }
  rep(i, 4) {
    if(X >= (i+1)*(i+1)*(i+1)*(i+1)*(i+1)) {
      co = (i+1)*(i+1)*(i+1)*(i+1)*(i+1);
      ma = max(ma, co);
    }
  }
  rep(i, 4) {
    if(X >= (i+1)*(i+1)*(i+1)*(i+1)*(i+1)) {
      co = (i+1)*(i+1)*(i+1)*(i+1)*(i+1);
      ma = max(ma, co);
    }
  }
  rep(i, 4) {
    if(X >= (i+1)*(i+1)*(i+1)*(i+1)*(i+1)*(i+1)) {
      co = (i+1)*(i+1)*(i+1)*(i+1)*(i+1)*(i+1);
      ma = max(ma, co);
    }
  }
  cout << ma << endl;
}