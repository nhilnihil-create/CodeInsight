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
 
const ll inf = 1e9 + 7;
const ll Mod = 998244353;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);


int main(){
  int N; ll Z, W;
  cin >> N >> Z >> W;

  ll A[N];
  for (int i = 0; i < N; i++) cin >> A[i];

  if (N == 1){
    cout << abs(A[0] - W) << endl;
    return 0;
  }

  ll ans = max(abs(A[N - 1] - A[N - 2]), abs(A[N - 1] - W));
  cout << ans << endl;

  return 0;
}
