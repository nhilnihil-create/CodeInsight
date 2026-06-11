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

int bit(int a, int i){
  return (a >> i) & 1;
}

int main(void){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int l = 0, r = 0;
  int b = 0;
  ll res = 0;
  while (l < n){
    while (r < n){
      int ok = 1;
      for (int i = 0; i < 20; i++){
        if (bit(b, i) == bit(a[r], i) && bit(a[r], i) == 1){
          ok = 0;
        }
      }
      if (ok){
        b ^= a[r];
        r++;
      }
      else {
        break;
      }
    }
    res += r - l;
    b ^= a[l];
    l++;
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
