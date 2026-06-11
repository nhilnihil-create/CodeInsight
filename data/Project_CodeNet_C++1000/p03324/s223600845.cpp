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
  int D,N;
  cin >> D >> N;
  if(D==0&&N!=100)
  {
    cout << N << endl;
  }
  else if(D==0&&N==100)
  {
    cout << 101 << endl;
  }
  else if(D==1&&N!=100)
  {
    cout << 100*N << endl;
  }
  else if(D==1&&N==100)
  {
    cout << 10100 << endl;
  }
  else if(D==2&&N!=100)
  {
    cout << 10000*N << endl;
  }
  else if(D==2&&N==100)
  {
    cout << 1010000 << endl;
  }
  return 0;
}
