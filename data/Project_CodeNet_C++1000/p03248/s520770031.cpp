#include <bits/stdc++.h>
#pragma once
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
#define endn "\n"
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 


////////////////////////////////////////////////////////////////////
///////////////////////___modpow___////////////////////
ll modpow(ll a,  ll n, const ll &MOD = MOD){
  ll ret = n == 0 ? 1 : modpow(a, n/2, MOD);
  (ret *= ret) %= MOD;
  if(n%2)((ret *= a) %= MOD);
  return ret;
}
///////////////////////___modinv___////////////////////
ll modinv(ll d, const ll &MOD = MOD){
  return modpow(d, MOD-2, MOD);
}
////////////////////////////////////////////////////////////////////
vector<P>ans;
signed main(){
  string s;cin>>s;int n = s.length();s = '#' + s;
  bool b = true;
  repd(i,1,n/2+1)b = b && (s[i] == s[n-i]);
  if(s[1] == '0' || s[n] == '1' || !b){
    cout << -1 << endl;return 0;
  }
  int last = n;
  for(int i = n-1;i >= 1;i--){
    ans.push_back(P(last, i));
    if(i > n/2)continue;
    if(s[i] == '1'){
      last = i;
    }
  }
  rep(i,n-1)cout << ans[i].first << " " << ans[i].second << endl;
}
