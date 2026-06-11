#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define int long long
#define pb push_back

using namespace std;
typedef long long ll;

const int mod = 998244353;
const int maxn = 3e5 + 5;

int power(int a, int b)
{
  if (b == 0) return 1;
  int res = power(a, b / 2);
  if (b & 1) return 1ll * res * res % mod * a % mod;
  return 1ll * res * res % mod;
}

int fact[maxn], ifact[maxn];
int N, A, B, K;

int kCn(int k, int n)
{
  if (k > n) return 0;
  return 1ll * fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

signed main(void)
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  if (fopen("A.INP", "r")){
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  }
  cin >> N >> A >> B >> K;
  fact[0] = 1;
  for (int i = 1; i <= N; ++i){
    fact[i] = 1ll * fact[i - 1] * i % mod;
  }
  ifact[N] = power(fact[N], mod - 2);
  for (int i = N - 1; i >= 0; --i){
    ifact[i] = 1ll * ifact[i + 1] * (i + 1) % mod;
  }
  int res = 0;
  for (int i = 0; i <= N; ++i){
    int j = (K - i * A) / B;
    if (j < 0 || j > N || j * B + i * A != K) continue;
    res += 1ll * kCn(i, N) * kCn(j, N) % mod;
    res %= mod;
  }
  cout << res << '\n';
}
