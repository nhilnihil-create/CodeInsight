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

ll N, M;
ll A[100001], sum[100001];

int Solve(){
  sort(sum, sum + N + 1);
  ll ans = 0, cnt = 1;
  for (int i = 1; i < N + 1; i++){
    if (sum[i] == sum[i - 1]) cnt++;
    else{
      ans += cnt * (cnt - 1) / 2;
      cnt = 1;
    }
  }
  ans += cnt * (cnt - 1) / 2;
  cout << ans << endl;
  return 0;
}

int main(){
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 1; i < N + 1; i++){
    sum[i] = sum[i - 1] + A[i - 1];
    sum[i] %= M;
  }
  
  Solve();
  
  return 0;
}