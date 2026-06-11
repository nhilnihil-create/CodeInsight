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
  int N,T;
  cin >> N >> T;
  vector<int> c(N),t(N);
  rep(i,N)
  {
    cin >> c[i] >> t[i];
  }
  int mi = 10000;
  rep(i,N)
  {
    if(t[i]<=T)
    {
      mi = min(mi,c[i]);
    }
  }
  if(mi<=1000)
  {
    cout << mi << endl;
  }
  else if (mi = 10000)
  {
    cout << "TLE" << endl;
  }
  return 0;
}
