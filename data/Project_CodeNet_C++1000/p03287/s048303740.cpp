#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
  int n,m;cin >> n >> m;
  map<int,int> mp;
  mp[0]++;
  vector<ll> a(n+1,0);
  rep(i,n){
    cin >> a[i+1];
    a[i+1] += a[i];
    mp[a[i+1]%m]++;
  }
  ll ans = 0;
  for(auto p:mp){
    ans += ll(p.second)*ll(p.second-1)/2;
  }

  cout << ans << endl;
}