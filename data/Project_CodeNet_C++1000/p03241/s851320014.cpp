#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

using namespace std;
using ll = long long;

const ll MOD = 1000000007LL; // = 10^9 + 7
const double PI = 3.14159265358979;

// 素数判定
bool isPrime(int a) {
    if (a == 1) return false;
    for (int i = 2; i * i <= a; i++) {
        if(a % i == 0) return false;
    }
    return true;
}

ll n, m;
vector<ll> factor;
vector<ll> factors;
void dfs(int num, int ind)
{
  if (ind >= factor.size()) 
  {
    factors.emplace_back(num);
    return;
  }
  if (num * factor[ind] * n > m)
  {
    factors.emplace_back(num);
    return;
  }
  else
  {
    dfs(num * factor[ind], ind + 1);    
    dfs(num, ind + 1);
  }
}

void solve()
{
  cin >> n >> m;

  if (n == 1)
  {
    cout << m;
    return;
  }


  ll ans = 1;
  for(ll i = 2; i * i <= m; ++i)
  {
    if (m % i == 0 && i * n <= m)
    {
      ans = max(ans, i);
      if (m / i * n <= m) ans = max(ans, m / i);
    }
  }
  cout << ans;
  return;


  //*
  if (isPrime(m))
  {
    cout << 1;
    return;
  }
  //*/

  int temp_m = m;
  for(int p = 2; p * p <= temp_m; ++p)
  {
    while(temp_m % p == 0)
    {
      if (p <= n) factor.emplace_back(p);
      temp_m /= p;
    }
  }

  factors.emplace_back(1);
  dfs(1, 0);
  sort(factors.begin(), factors.end());
  factors.erase( unique(factors.begin(), factors.end()), factors.end() );

  cout << factors.back();


}

int main()
{
  fastio;
  solve();

  return 0;
}