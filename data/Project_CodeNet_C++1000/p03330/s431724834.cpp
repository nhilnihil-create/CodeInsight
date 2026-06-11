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
  int n, C;
  cin >> n >> C;
  vector<vector<ll>> d(C, vector<ll>(C));
  vector<vector<ll>> c(n, vector<ll>(n));
  for (int i = 0; i < C; i++){
    for (int j = 0; j < C; j++){
      cin >> d[i][j];
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> c[i][j];
      c[i][j]--;
    }
  }
  vector<vector<ll>> rem(3, vector<ll>(C, 0));
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < C; j++){
      for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
          if ((x + y) % 3 == i && c[x][y] != j){
            rem[i][j] += d[c[x][y]][j];
          }
        }
      }
    }
  }

  ll res = INF;
  for (int i = 0; i < C; i++){
    for (int j = 0; j < C; j++){
      for (int k = 0; k < C; k++){
        if (i != j && j != k && i != k){
          res = min(res, rem[0][i] + rem[1][j] + rem[2][k]);
        }
      }
    }
  }


  cout << res << endl;

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
