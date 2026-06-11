#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>

#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i, s, n) for(int i=s; i<n; i++)
#define dup(x,y) (((x)+(y)-1)/(y)) // dup * y >= x なる最小のdup.
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;

int main() {
  ll N, K;
  cin >> N >> K;
  vector<pair<ll, int>> menu(N); // d, t 
  rep(i, N) cin >> menu[i].second >> menu[i].first;

  sort(menu.begin(), menu.end());
  reverse(menu.begin(), menu.end());  // dが大きい順

  // menu を 初期解 ... 確定ネタ、被りネタ
  // と、交代ネタ　と、 使わないネタに分ける
  ll S0 = 0; // 確定ネタと初期被りネタの d の和
  priority_queue<ll> S1_r; // 被りネタのd * -1
  priority_queue<ll> T; // 交代ネタのd

  map<int, int> used; // <id, 使用数>
  // menu の最初のK個は 初期解になる
  int neta = 0;
  rep(i, K) {
    int id = menu[i].second;
    if(used[id]==0) {
      used[id] = 1;
      S0 += menu[i].first;
      neta++;
    } else if(used[id]==1) {
      S0 += menu[i].first;
      S1_r.push(-1 * menu[i].first);
    }
  }
  // menu のK+1個目以降は、各ネタで最高d のみ交代ネタに入る
  rep2(i, K, N) {
    int id = menu[i].second;
    if(used[id]==0) {
      T.push(menu[i].first);
      used[id] = 1;
    }
  }

  vector<ll> f(N+1, -1e18);
  f[neta] = S0;
  int neta0 = neta;

  while(!S1_r.empty() && !T.empty()) {
    f[neta+1] = f[neta] + S1_r.top() + T.top();
    S1_r.pop();
    T.pop();
    neta++;
  }

 
  ll ans = 0;
  rep2(i, neta0, neta+1) {
    //cout << f[i] << ' ';
    ans = max(ans, f[i] + (ll)i*i);
  }
  // cout << endl;
  cout << ans << endl;

  return 0;
}
