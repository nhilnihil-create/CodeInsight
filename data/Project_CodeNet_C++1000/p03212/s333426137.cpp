#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

bool chk(ll i, vector<int> &v){
  vector<bool> c(3, false);
  while(i != 0){
    int n = i % 10;
    rep(j, 3){
      if(v.at(j) == n) c.at(j) = true;
    }
    i /= 10;
  }
  rep(j, 3){
    if(c.at(j) == false) return false;
  }
  return true;
}

int main(){
  int n;
  cin >> n;
  queue<pair<ll, bool>> q;
  q.push(make_pair(3, false));
  q.push(make_pair(5, false));
  q.push(make_pair(7, false));
  int ans = 0;
  vector<int> v = {3, 5, 7};
  while(!q.empty()){
    auto p = q.front(); q.pop();
    bool f = true;
    if(p.second == false){
      f = chk(p.first, v);
    }
    if(p.first <= n && f == true) ans++;
    p.first *= 10;
    rep(i, 3){
      if(p.first + v.at(i) > n) continue;
      q.push(make_pair(p.first+v.at(i), f));
    }
  }
  cout << ans << endl;
  return 0;
}