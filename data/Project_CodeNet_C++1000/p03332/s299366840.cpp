#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const int INF = 1e9;
const int maxN = 3e5 + 55;


ll fact[maxN], rev[maxN];

ll quickPow(ll x, ll y){
  if(y == 0){
    return 1;
  }

  ll tmp = quickPow(x, y / 2);
  if(y % 2){
    return (((tmp * tmp) % MOD) * (x % MOD)) % MOD;
  }

  return (tmp * tmp) % MOD;
}

void preCal(){
  fact[0] = 1;
  for(int i = 1; i < maxN; i++){
    fact[i] = (fact[i - 1] * i) % MOD;
  }

  for(int i = 0; i < maxN; i++){
    rev[i] = quickPow(fact[i], MOD - 2);
  }
}

ll nCk(ll N, ll K){
  ll ans = fact[N];
  ans = (ans * rev[K]) % MOD;
  ans = (ans * rev[N - K]) % MOD;

  return ans;
}

ll n, a, b, k;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  preCal();

  cin >> n >> a >> b >> k;

  ll fRes = 0;

  for(ll red = 0; red <= n; red++){
    //red * a + blue * b == k
    if((k - red * a) % b == 0){
      ll blue = (k - red * a) / b;
      if(0 <= blue && blue <= n){
        fRes = (fRes + ((nCk(n, red) * nCk(n, blue)) % MOD)) % MOD;
      }
    }
  }

  cout << fRes << '\n';

  return 0;
}
