#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 9;
const int MOD = 998244353;

int f[N];

int powr(int n, int k){
  if(k==0)return 1;
  int m = powr(n,k/2);
  m = (m * 1ll * m) % MOD;
  if(k&1) m = (m * 1ll * n) % MOD;
  return m;
}

int comb(int n, int k){
  int res = f[n];
  res = (res * 1ll * powr((f[k] * 1ll * f[n - k]) % MOD, MOD-2)) % MOD;
  return res;
}

int main(){
  fastIO;
  f[0] = 1;
  for(int i = 1; i < N ; i ++ ){
    f[i] = (f[i - 1] * 1ll * i) % MOD;
  }
  int n;
  cin >> n;
  ll a, b;
  cin >> a >> b;
  ll k;
  cin >> k;
  int ret = 0;
  ll v1, v2;
  for(int i = 0 ; i <= n; i ++ ){
    v1 = i * a;
    if(v1 > k){
      break;
    }
    v2 = k - v1;
    if(v2 % b != 0) continue;
    v1 /= a;
    v2 /= b;
    if(v1 <= n && v2 <= n){
      ret = (ret + (comb(n, v1) * 1ll * comb(n, v2)) % MOD) % MOD;
    }
  }
  cout << ret << "\n";
  return 0;
}