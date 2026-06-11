#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
  ll N, K, a;
  cin >> N >> K;
  map<ll, ll> mp;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

  while(cin >> a){
      mp[a] += 1;
  }

  ll ans = 0;
  ll max = 0;
  for(auto x:mp){
    pq.push({x.second, x.first});
  }
  while(pq.size() > K){
    ans += pq.top().first;
    pq.pop();      
  }

  cout << ans << endl;
}
