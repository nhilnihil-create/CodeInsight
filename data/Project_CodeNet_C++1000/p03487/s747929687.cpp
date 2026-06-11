#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll N;
  cin >> N;
  ll a;
  map<ll, ll> cnt;
  rep(i, N){
    cin >> a;
    cnt[a]++;
  }

  ll ans = 0;

  for(auto it = cnt.begin(); it != cnt.end(); it++){
    if(it->first != it->second){
      if(it->first > it->second) ans += it->second;
      else ans += it->second - it->first;
    }
  }

  cout << ans << endl;
  
  return 0;
}
