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
  int N;
  cin >> N;
  if(N<112)
  {
    cout << 111 << endl;
  }
  else if(N<223)
  {
    cout << 222 << endl;
  }
  else if(N<334)
  {
    cout << 333 << endl;
  }
  else if(N<445)
  {
    cout << 444 << endl;
  }
  else if(N<556)
  {
    cout << 555 << endl;
  }
  else if(N<667)
  {
    cout << 666 << endl;
  }
  else if(N<778)
  {
    cout << 777 << endl;
  }
  else if(N<889)
  {
    cout << 888 << endl;
  }
  else
  {
    cout << 999 << endl;
  }
  return 0;
}
