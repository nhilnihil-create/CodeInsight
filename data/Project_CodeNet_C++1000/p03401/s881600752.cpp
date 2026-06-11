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
  int n;
  cin >> n;
  vector<int> a(n + 2, 0);
  for (int i = 1; i <= n; i++)
    cin >> a[i];



  int res;
  res = abs(a[2] - a[0]);
  for (int i = 3; i < n + 2; i++){
    res += abs(a[i] - a[i-1]);
  }

  cout << res << endl;
  for (int i = 2; i <= n; i++){
    res += abs(a[i-1] - a[i-2]) + abs(a[i-1] - a[i+1]) - abs(a[i] - a[i-2]) - abs(a[i] - a[i+1]);
    cout << res << endl;
  }
  

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
