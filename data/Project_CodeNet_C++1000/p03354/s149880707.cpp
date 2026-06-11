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
#define N 100000

int parent[N + 1];

int findroot(int a){
  if (parent[a] == a)
    return a;

  int newparent = findroot(parent[a]);
  parent[a] = newparent;
  return newparent;
}

int main(void){
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
  }
  int x, y;
  for (int i = 1; i < n + 1; i++){
    parent[i] = i;
  }
  for (int i = 0; i < m; i++){
    cin >> x >> y;
    if (findroot(x) != findroot(y)){
      parent[findroot(x)] = y;
    }
  }

  int res = 0;
  for (int i = 0; i < n; i++){
    if (findroot(p[i]) == findroot(i + 1)){
      res++;
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
