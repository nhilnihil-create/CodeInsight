#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
const int MAX = 510000;
const ll MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;//a^n%mod
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
long long modinv(long long a, long long m) {
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

int main(){
  string s;
  cin >> s;
  ll n=s.size();
  ll a[n+1];
  a[0]=0;
  ll c[n+1];
  ll b[n+1];
  b[0]=0;
  ll bb[n+1];
  bb[n]=0;
  c[n]=0;
  rep(i,n){
    if(s[i]=='A')a[i+1]=a[i]+1;
    else a[i+1]=a[i];
    if(s[i]=='?')b[i+1]=b[i]+1;
    else b[i+1]=b[i];
    if(s[n-1-i]=='C')c[n-1-i]=c[n-i]+1;
    else c[n-1-i]=c[n-i];
    if(s[n-1-i]=='?')bb[n-1-i]=bb[n-i]+1;
    else bb[n-1-i]=bb[n-i];
  }
  ll q[n];
  q[0]=1;
  rep(i,n-1)q[i+1]=q[i]*3%MOD;
  ll ans=0;
  //cout << s << n << endl;
  rep(i,n){
    if(s[i]=='B'||s[i]=='?'){
      //cout << 111 << endl;
      ans=(ans+(a[i]*q[b[i]]+(b[i]*q[max((ll)0,b[i]-1)])%MOD)%MOD*((c[i+1]*q[bb[i+1]]+(bb[i+1]*q[max(bb[1+i]-1,(ll)0)])%MOD)%MOD)%MOD)%MOD;
    }
    //cout << a[i] << " " << b[i] << " " << c[i+1] << " " << bb[i+1] << " " << q[b[i]] << " " << q[max((ll)0,b[i]-1)] << endl;
    //cout << ans << " " << -1<< endl;
  }
  cout << ans << endl;
}
