#include <bits/stdc++.h>
//#pragma once
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
typedef pair<double,double> P;
const ll INF = 1e18;
const int MOD = 1000000007;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 

ll modpow(ll a,  ll n, const ll &MOD = MOD){
  ll ret = n == 0 ? 1 : modpow(a, n/2, MOD);
  (ret *= ret) %= MOD;
  if(n%2)((ret *= a) %= MOD);
  return ret;
}

string s;int n, a[110000],b[110000],c[110000],q[110000];
signed main(){
  cin>>s;n = s.length();
  rep(i,n){
    if(s[i] == 'A')a[i+1]++;
    else if(s[i] == 'B')b[i+1]++;
    else if(s[i] == 'C')c[i+1]++;
    else q[i+1]++;
  }
  repd(i,1,n+1){
    a[i] += a[i-1];
    b[i] += b[i-1];
    c[i] += c[i-1];
    q[i] += q[i-1];
  }
  int ans = 0;
  repd(i,1,n+1){
    if(s[i-1] == 'B' || s[i-1] == '?'){
      int l = (a[i-1]*modpow(3,q[i-1])%MOD + q[i-1]*modpow(3,q[i-1]-1)%MOD)%MOD,
          r = ((c[n]-c[i])*modpow(3, q[n]-q[i])%MOD + (q[n]-q[i])*modpow(3, q[n]-q[i]-1)%MOD)%MOD;
      ans = (ans + l*r%MOD)%MOD;
    }
  }
  cout << ans << endl;
}
