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
  vector<int> x(N);
  rep(i,N)
  {
    cin >> x[i];
  }
  int m = 1000000000;
  m = min(X,m);
  rep(i,N)
  {
    m = min(m,x[i]);
  }
  int M = 1000000000;
  if(N==1)
  {
    cout << abs(x[0]-X) << endl;
    return 0;
  }
  rep(i,N-1)
  {
    if(x[i]==m)
    {
      continue;
    }
    M = min(M,gcd(x[i]-m,x[i+1]-m));
  }
  if(X!=m)
  {
    if(x[0]!=m)
    {
      M = min(M,gcd(x[0]-m,X-m));
    }
    else
    {
      M = min(M,gcd(x[1]-m,X-m));
    }
    
  }
  cout << M << endl;
  return 0;
}
