#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,ll> P;

bool comp(const P &a, const P &b) {
  return a.second > b.second;
}

int main(){
  int n, k;
  cin >> n >> k;
  vector<P> sushi;
  rep(i,n) {
    int t, d;
    cin >> t >> d;
    sushi.push_back({t,d});
  }
  sort(sushi.begin(), sushi.end(), comp);
  map<int,int> check;
  ll res = 0;
  rep(i,k) {
    check[sushi[i].first]++;
    res += sushi[i].second;
  }
  priority_queue<ll> que;
  ll now = check.size();
  /*まだ選んでないネタの最大値 */
  for (int i = k; i < n; i++) {
    if (check.find(sushi[i].first) == check.end()) que.push(sushi[i].second),check[sushi[i].first]++;
  }
  ll cur = res;
  res += now*now;
  for (int i = k-1; i >= 0; i--) {
    if (que.empty()) continue;
    P a = sushi[i];
    ll b = que.top();
    if (check[a.first] == 1) continue;
    cur -= a.second;
    now++;
    check[a.first]--;
    cur += b;
    que.pop();
    res = max(cur + now*now ,res);
  }
  cout << res << endl;
  return 0;
} 