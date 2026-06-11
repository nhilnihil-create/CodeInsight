#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main () {
  ll X, Y;
  cin >> X >> Y;
  int ans = 0;
  
  while (X <= Y) {
    X *= 2;
    ans++;
  }
  
  cout << ans;
}