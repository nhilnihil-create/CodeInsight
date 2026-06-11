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

int n,m,x[1100],y[1100],z[1100];
signed main(){
  cin>>n>>m;
  rep(i,n)cin>>x[i]>>y[i]>>z[i];
  int ans = 0;
  rep(bit, 1<<3){
    priority_queue<int> q;
    rep(i,n){
      int s = 0;
      s += x[i] * (bit&1? 1 : -1);
      s += y[i] * (bit&2? 1 : -1);
      s += z[i] * (bit&4? 1 : -1);
      q.push(s);
    }
    int sum = 0;
    rep(i,m)sum += q.top(), q.pop();
    chmax(ans, sum);
  }
  cout << ans << endl;
}
