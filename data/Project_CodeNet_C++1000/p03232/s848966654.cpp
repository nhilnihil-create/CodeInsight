#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

static const ll MOD = 1000000007LL;

ll extgcd(ll a, ll b, ll &x, ll &y){
  ll d = a;
  if(b!=0){
    d = extgcd(b,a%b,y,x);
    y -= (a/b)*x;
  }else{
    x = 1; y = 0;
  }
  return d;
}

ll mod_inverse(ll a, ll m){
  ll x, y;
  extgcd(a, m, x, y);
  return (m+x%m)%m;
}

vector<ll> calc(int N){
  ll kaijo = 1;
  REP(i,1,N+1){
    kaijo *= i;
    kaijo %= MOD;
  }
  
  vector<ll> inv(N+1);
  REP(i,1,N+1){
    inv[i] = mod_inverse(i, MOD);
  }
  vector<ll> sum(N+1, 0);
  REP(i,1,N+1){
    sum[i] = (sum[i-1] + inv[i])%MOD;
  }

  vector<ll> ret(N, 0);
  rep(i,N){
    int a = i+1;
    int b = N-i;
    ret[i] = sum[a] + sum[b];
    ret[i] %= MOD;
    ret[i] += MOD - sum[1];
    ret[i] %= MOD;
    ret[i] *= kaijo;
    ret[i] %= MOD;
  }
  return ret;
}


int main(){
  int N;
  cin >> N;
  vector<ll> v;
  rep(i,N){
    ll a;
    cin >> a;
    v.push_back(a);
  }

  vector<ll> w = calc(N);
  ll ret = 0;
  rep(i,N){
    ret += w[i] * v[i];
    ret %= MOD;
  }

  cout << ret << endl;
  
  return 0;
}

