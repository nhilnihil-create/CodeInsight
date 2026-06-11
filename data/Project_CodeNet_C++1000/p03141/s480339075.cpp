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
  int n;
  cin >> n;
  takahashi.resize(n);
  aoki.resize(n);
  rep(i, n) {
    cin >> takahashi[i] >> aoki[i];
  }
  vector<int> taka(n);
  vector<int> ao(n);
  iota(taka.begin(), taka.end(), 0);
  iota(ao.begin(), ao.end(), 0);
  sort(taka.begin(), taka.end(), custom_1);
  sort(ao.begin(), ao.end(), custom_2);
  vector<bool> used(n);
  int t = 0;
  int a = 0;
  ll taka_total = 0LL;
  ll ao_total = 0LL;
  rep(i, n) {
    if(i % 2 == 0) {
      for(int j=t;j<n;j++) {
        if(used[taka[j]]) continue;
        else {
          t = j + 1;
          used[taka[j]] = true;
          taka_total += takahashi[taka[j]];
          break;
        }
      }
    }
    else {
      for(int j=a;j<n;j++) {
        if(used[ao[j]]) continue;
        a = j + 1;
        used[ao[j]] = true;
        ao_total += aoki[ao[j]];
        break;
      }
    }
  }

  cout << taka_total - ao_total << endl;
}
