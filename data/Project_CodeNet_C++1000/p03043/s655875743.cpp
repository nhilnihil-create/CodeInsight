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

int main()
{
  cout << fixed << setprecision(10);
  int N,K;
  cin >> N >> K;
  double ans = 0;
  for(int i=1;i<N+1;i++)
  {
    if(i>=K)
    {
      double k = 1;
      k /= N;
      ans += k;
    }
    else
    {
      double a = 1;
      a /= N;
      double n = i;
      while(n<K)
      {
        n *= 2;
        a /= 2;
      }
      ans += a;
    }
  }
  cout << ans << endl;
  return 0;
}
