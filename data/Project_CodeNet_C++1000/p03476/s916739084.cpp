#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
bool is_prime(long long N)
{
  if (N == 1)
    return false;
  for (long long i = 2; i * i <= N; ++i)
  {
    if (N % i == 0)
      return false;
  }
  return true;
}

int main()
{
  cout << fixed << setprecision(10);
  int Q;
  cin >> Q;
  vector<int> vec(100010);
  int n = 0;
  rep(i,100010)
  {
      if(is_prime(i)&&is_prime((i+1)/2)&&i%2==1)
      {
        n ++;
        vec[i] = n;
      }
      else
      {
        vec[i] = n;
      }
  }
  rep(i,Q)
  {
    int l,r;
    cin >> l >> r;
    l--;
    cout << vec[r] - vec[l] << endl;
  }
  return 0;
}
