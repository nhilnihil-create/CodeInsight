#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int (i)=0;(i)<(n);(i)++)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
vector<ll> takahashi;
vector<ll> aoki;
bool custom_1(int a, int b) {
  if(takahashi[a] - aoki[b] == takahashi[b] - aoki[a]) return (takahashi[a] > takahashi[b]);
  else return (takahashi[a] - aoki[b] > takahashi[b] - aoki[a]);
}
bool custom_2(int a, int b) {
  if(aoki[a] - takahashi[b] == aoki[b] - takahashi[a]) return (aoki[a] > aoki[b]);
  else return (aoki[a] - takahashi[b] > aoki[b] - takahashi[a]);
}
bool custom1 (pair<int, int> a, pair<int, int> b) {
  return (a.first < b.first);
}
bool custom2(pair<int, int> a, pair<int, int> b) {
  return (a.second < b.second);
}

const int MAX = 200005;
const long long MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

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

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
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

int main() {
  string s;
  cin >> s;
  if(s.size() == 26) {
    int max = 0;
    int idx = -1;
    for(int i = 24;i>=0;i--) {
      if(s[i] < s[i+1]) {
        idx = i;
        break;
      }
    }
    if(idx == -1) cout << -1 << endl;
    else {
      char q = 'z';
      for(int i=25;i>idx;i--) {
        if(s[i] > s[idx]) chmin(q, s[i]);
      }
      cout << s.substr(0, idx) + q << endl;
    }
  }
  else {
    vector<int> used(26);
    rep(i, s.size()) {
      used[s[i]-'a'] = 1;
    }
    char q;
    rep(i, 26) {
      if(!used[i]) {
        q = 'a' + i;
        break;
      }
    }

    cout << s + q << endl;
  }
}
