#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int n,m;
  cin >> n >> m;
  priority_queue<ll> q;
  rep(i, n) {//各要素をキューに追加
    ll a; cin >> a;
    a*=-1;
    q.push(a);
  }

  vector<pair<ll,ll>> bc;
  
  rep(i,m){
    ll b, c; cin >> b >> c;
    c *=-1;
    bc.emplace_back(c,b);
  }
  sort(bc.begin(), bc.end());
  ll count=0;
  for(auto p:bc){
//    cout << p.first << ' ' << p.second << endl;
    rep(j,p.second){
      ll x=q.top();
      if(p.first<x && count<=n) {
        q.pop();
        q.push(p.first);
        count +=1;
      }
      else{
        ll ans = 0;
        while (!q.empty()) {
          ans += q.top(); q.pop();
          }
          ans *= -1;
          cout << ans << endl;
          return 0;
      }
    }
  }
  ll ans = 0;
  while (!q.empty()) {
    ans += q.top(); q.pop();
    }
    ans *= -1;
    cout << ans << endl;
    return 0;
  

/*
  int count=0;
  for(auto p: bc){
    for(i,p.second){

      }

    }
*/
}
