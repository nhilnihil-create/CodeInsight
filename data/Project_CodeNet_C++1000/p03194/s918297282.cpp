#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "math.h"
 
using namespace std;
typedef long long ll;
 
ll power_int(ll a, int b)
{
  ll x = 1;
  while (b > 0)
  {
    x *= a;
    b--;
  }
  return x;
}
 
vector<int> decompPrimeMatrix(ll n)
{
  const int SIZE = 1000010;	//ここは変える
  vector<int> ans(SIZE);
  ll i = 2;
  while (i < SIZE)
  {
    if (n == 1)
    {
      break;
    }
    if (n % i == 0)
    {
      ans[i]++;
      n /= i;
    }
    else
    {
      i++;
    }
  }
  return ans;
}
 
int main()
{
  ll n, p;
  ll ans = 1;
  cin >> n >> p;
  if (n == 1)
  {
    cout << p << "\n";
  }
  else
  {
    vector<int> v = decompPrimeMatrix(p);
    for (int i = 1; i < 1000010; i++)
    {
      ans *= power_int(i, (v[i] / n));
    }
    cout << ans << "\n";
  }
}