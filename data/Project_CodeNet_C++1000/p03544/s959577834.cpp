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
ll dp[1000];

int main()
{
  cout << fixed << setprecision(10);
  int N;
  cin >> N;
  dp[0] = 2;
  dp[1] = 1;
  for(int i=2;i<87;i++)
  {
    dp[i] = dp[i-1] +dp[i-2];
  }
  cout << dp[N] << endl;
  return 0;
}
