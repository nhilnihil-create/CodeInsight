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
  ll K,A,B;
  cin >> K >> A >> B;
  if(K<=A)
  {
    cout << K + 1 << endl;
  }
  else
  {
    if(A+2>=B)
    {
      cout << K + 1 << endl;
    }
    else
    {
      ll M = K-A-1;
      if(M%2==0)
      {
        cout << B + M/2 * (B-A) << endl;
      }
      else
      {
        cout << B + (M-1)/2 * (B-A) + 1 << endl;
      }
      
    }
    
  }
  return 0;
}
