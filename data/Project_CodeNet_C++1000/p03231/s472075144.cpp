#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());
using ll = long long;

ll gcd(ll a, ll b)
{
  return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  ll N, M;
  cin >> N >> M;
  ll L = lcm(N, M);
  string S, T;
  cin >> S >> T;

  map<long long, char> X;
  rep(i, N)
  {
    long long n = i * L / N;
    X[n] = S[i];
  }

  bool is_ok = true;
  rep(i, M)
  {
    long long m = i * L / M;
    if (X[m] != 0 && X[m] != T[i])
      is_ok = false;
  }

  if (is_ok)
    cout << L << endl;
  else
    cout << -1 << endl;

  return 0;
}