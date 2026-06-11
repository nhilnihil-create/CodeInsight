#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9
#define PI 3.14159265359
#define MOD 1000000007
#define ALL(v) v.begin(),v.end()
#define ALLR(v) v.rbegin(),v.rend()
#define F first
#define S second
typedef long long ll;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
//isPrime
//modpow modinv
//getDigit
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
int main() {
  cout << fixed << setprecision(10);
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<ll> s(n+1);
  rep(i,n){
    s[i+1]=s[i]+a[i];
  }
  map<ll,ll> mp;
  rep(i,n+1){
    mp[s[i]]++;
  }
  ll ans = 0;
  for(auto p:mp){
    ll b = p.second;
    ans += b*(b-1)/2;
  }
  cout << ans << endl;
}

