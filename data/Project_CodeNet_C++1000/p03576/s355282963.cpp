//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <time.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
 
const ll nmax = 1e9 + 7;
const ll Mod = 998244353;
const double PI = 2 * asin(1);

int main(){
  int N, K; cin >> N >> K;
  ll X[N], Y[N];
  for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

  ll ans = 4e18;
  for (int i1 = 0; i1 < N; i1++){
    for (int i2 = 0; i2 < N; i2++){
      for (int i3 = 0; i3 < N; i3++){
        for (int i4 = 0; i4 < N; i4++){
          ll x1 = min(min(X[i1], X[i2]), min(X[i3], X[i4]));
          ll x2 = max(max(X[i1], X[i2]), max(X[i3], X[i4]));
          ll y1 = min(min(Y[i1], Y[i2]), min(Y[i3], Y[i4]));
          ll y2 = max(max(Y[i1], Y[i2]), max(Y[i3], Y[i4]));
          int cnt = 0;
          for (int i = 0; i < N; i++){
            if (x1 <= X[i] && X[i] <= x2 && y1 <= Y[i] && Y[i] <= y2) cnt++;
          }
          if (cnt >= K){
            ans = min(ans, (x2 - x1) * (y2 - y1));
          }
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}
