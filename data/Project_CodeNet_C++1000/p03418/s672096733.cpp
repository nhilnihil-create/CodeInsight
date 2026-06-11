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
  ll N, K; cin >> N >> K;
  if (K == 0){
    cout << N * N << endl;
    return 0;
  }
  ll ans = 0;
  for (ll i = K + 1; i <= N; i++){
    ll now = (i - K) * (N / i);
    if (N % i >= K){
      now += (N % i) - K + 1;
    }
    ans += now;
  }
  cout << ans << endl;

  return 0;
}
