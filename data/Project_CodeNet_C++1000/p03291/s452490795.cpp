#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}


ll const mod = 1e9+7;
// べき乗
int64_t modpow(int64_t x, int64_t n) {
    x = x%mod;
    if(n==0) return 1;  //再帰の終了条件

    else if(n%2==1) {
        return (x*modpow(x, n-1))%mod;  //nが奇数ならnを1ずらす
    }
    else return modpow((x*x)%mod, n/2)%mod;  //nが偶数ならnが半分になる
}

//逆元　a/b の modをとるとき -> a*modinv(b)%mod
long long modinv(long long a, long long m = 1e9+7) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m; 
  if (u < 0) u += m;
  return u;
}

int main() {
  ll Q=0;
  string S;
  cin >> S;
  int N=S.size();
  for (auto i:S) if(i=='?') Q++;
  vector<ll> a(N+1,0),b(N+1,0),c(N+1,0);
  rep2(i,1,N+1) {
    auto t = S[i-1];
    a[i] += a[i-1];
    b[i] += b[i-1];
    c[i] += c[i-1];
    if (t=='A') a[i]+=modpow(3,Q);
    else if (t=='B') b[i] += a[i-1];
    else if (t=='C') c[i] += b[i-1];
    else {
      a[i]+=modpow(3,Q-1);
      b[i] += a[i-1]*modinv(3)%mod;
      c[i] += b[i-1]*modinv(3)%mod;
    }
    a[i]%=mod;
    b[i]%=mod;
    c[i]%=mod;
    // printf("%lld %lld %lld\n",a[i],b[i],c[i]);
  }
  cout << c[N] << endl;
}