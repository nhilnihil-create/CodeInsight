#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T>
void chmin(T &a, T b) { a = min(a, b); }
template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

bool is_prime(ll num)
{
  if (num < 2)
    return false;
  else if (num == 2)
    return true;
  else if (num % 2 == 0)
    return false;

  double sqrt_num = sqrt(num);
  for (ll i = 3; i <= sqrt_num; i += 2)
  {
    if (num % i == 0)
      return false;
  }

  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> primes;
  rep(i, 2, 55556)
  {
    if (is_prime(i) && i % 5 == 1)
      primes.push_back(i);
    if (primes.size() == n)
      break;
  }

  rep(i, 0, n)
  {
    if (i > 0)
      cout << " ";
    cout << primes[i];
  }

  cout << endl;
}
