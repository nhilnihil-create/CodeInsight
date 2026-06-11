#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, k;
  cin >> n >> k;
  
  vector<vector<ll>> x(n, vector<ll>(2));
  for(int i = 0; i < n; i++) cin >> x.at(i).at(1) >> x.at(i).at(0);
  
  sort(x.rbegin(), x.rend());
  
  ll oisisa = 0;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  vector<ll> t(n + 1);
  for(int i = 0; i < k; i++){
    oisisa += x.at(i).at(0);
    t.at(x.at(i).at(1))++;
    pq.push(make_pair(x.at(i).at(0), x.at(i).at(1)));
  }
  
  ll count = 0;
  for(int i = 1; i <= n; i++){
    if(t.at(i) > 0) count++;
  }
  
  ll ans = oisisa + count * count;
  
  for(int i = k; i < n; i++){
    if(t.at(x.at(i).at(1)) > 0) continue;
    pair<ll, ll> p;
    while(!pq.empty()){
      p = pq.top();
      pq.pop();
      if(t.at(p.second) > 1){
        t.at(p.second)--;
        t.at(x.at(i).at(1))++;
        count++;
        oisisa -= p.first;
        oisisa += x.at(i).at(0);
        pq.push(make_pair(x.at(i).at(0), x.at(i).at(1)));
        break;
      }
    }
    ans = max(ans, oisisa + count * count);
  }
  
  cout << ans << '\n';
}