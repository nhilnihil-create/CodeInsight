#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main(void)
{
  ll x, y; cin >> x >> y;
  if(x % y == 0) {cout << -1 << endl; return 0;}
  cout << x << endl;
}
