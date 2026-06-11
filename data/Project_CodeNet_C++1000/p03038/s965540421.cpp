#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  ll n,m; cin >> n >> m;
  map<ll,ll,greater<int>> mp;
  rep(i,n){
    int a; cin >> a;
    mp[a]++;
  }
  rep(i,m){
    int b,c; cin >> b >> c;
    mp[c] += b;
  }
  ll ans = 0;
  for(auto x : mp){
    if(n == 0) break;
    ans += min(n,x.second)*x.first;
    n -= min(n,x.second);
  }
  cout << ans;
  cout << "\n";
  return 0;
}
