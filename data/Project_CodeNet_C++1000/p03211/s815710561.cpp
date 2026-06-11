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
  string S;
  cin >> S;
  int N = S.size();
  vector<int> s(N);
  rep(i,N)
  {
    s[i] = S[i]-48;
  }
  int m = 753;
  for(int i=0;i<N-2;i++)
  {
    m = min(m,abs(100*s[i]+10*s[i+1]+s[i+2]-753));
  }
  cout << m << endl;
  return 0;
}
