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
  int N,X;
  cin >> N >> X;
  vector<int> m(N);
  rep(i,N)
  {
    cin >> m[i];
  }
  int sum =0;
  int n = 1000;
  rep(i,N)
  {
    sum += m[i];
    n = min(n,m[i]);
  }
  X -= sum;
  cout << N+X/n << endl;
  return 0;
}
