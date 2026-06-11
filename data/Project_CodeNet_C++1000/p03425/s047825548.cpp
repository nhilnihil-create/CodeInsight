#include<bits/stdc++.h>
#define rep(i,n) for(ll i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF 1e9
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  int n; cin >> n;
  map<char,ll> mp;
  rep(i,n){
    string s; cin >> s;
    if(s[0]=='M' || s[0]=='A' || s[0]=='R' || s[0]=='C' || s[0]=='H') mp[s[0]]++;
  }
  if(mp.size() < 3) cout << 0;
  else{
    ll ans = 0;
    for(auto x : mp){
      for(auto y : mp){
        for(auto z : mp){
          if(!(x.first==y.first||y.first==z.first||z.first==x.first)){
            ans += x.second*y.second*z.second;
          }
        }
      }
    }
    cout << ans/6;
  }
  cout << "\n";
  return 0;
}
