#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

ll gcd(ll a, ll b);
ll power(ll n, ll k);
ll inv(ll n);
ll genfact(ll n, ll k);
ll fact(ll n);
ll nck(ll n, ll k);

int main(void){
  int n, K;
  cin >> n >> K;
  vector<ll> x(n), y(n), x2(n), y2(n);
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
    x2[i] = x[i];
    y2[i] = y[i];
  }
  sort(x2.begin(), x2.end());
  sort(y2.begin(), y2.end());
  ll m = 4*INF + 10;
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      for (int k = 0; k < n; k++){
        for (int l = k + 1; l < n; l++){
          int num = 0;
          for (int a = 0; a < n; a++){
            if (x2[i] <= x[a] && x[a] <= x2[j] && y2[k] <= y[a] && y[a] <= y2[l])
              num++;
          }
          ll t = (x2[j] - x2[i]) * (y2[l] - y2[k]);
          if (num >= K){
            m = min(m, t);
          }
        }
      }
    }
  }

  cout << m << endl;

  return 0;
}

ll gcd(ll a, ll b){
  if (a < b)
    return gcd(b, a);
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

ll power(ll n, ll k){
  ll res = 1;
  while(k > 0){
    if (k & 1) 
      res = res * n % MOD;
    n = n * n % MOD;
    k >>= 1;
  }
  return res;
}

ll genfact(ll n, ll k){

  ll res = 1;
  while (k >= 0){
    res = (res * (n - k)) % MOD;
    k--;
  }

  return res;
}

ll inv(ll n){
  return power(n, MOD - 2);
}

ll fact(ll n){
  return genfact(n, n - 1);
}

ll nck(ll n, ll k){
  if (k == 0)
    return 1;
  if (n <= 0)
    return 0;

  return ((genfact(n, k) % MOD) * inv(fact(k))) % MOD;
}
