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
  double N,T,A;
  cin >> N >> T >> A;
  vector<double> H(N);
  rep(i,N)
  {
    cin >> H[i];
  }
  vector<double> warm(N);
  rep(i,N)
  {
    warm[i] = T - H[i] * 0.006;
  }
  double m = 1111;
  int n = 0;
  rep(i,N)
  {
    if(abs(warm[i]-A)<m)
    {
      m = abs(warm[i]-A);
      n = i+1;
    }
  }
  cout << n << endl;
  return 0;
}
