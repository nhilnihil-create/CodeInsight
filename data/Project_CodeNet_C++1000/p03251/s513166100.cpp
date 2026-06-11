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
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  vector<int> x(N), y(M);
  bool ans = false;
  rep(i, N)
  {
    cin >> x[i];
  }
  rep(i, M)
  {
    cin >> y[i];
  }
  for (int i = X + 1; i <= Y; i++)
  {
    bool a = true;
    rep(j, N)
    {
      if (x[j] >= i)
      {
        a = false;

        break;
      }
    }
    rep(j, M)
    {
      if (y[j] < i)
      {
        a = false;
        break;
      }
    }
      if (a == true)
      {
        ans = true;
        break;
      }
  }
    if (X >= Y)
    {
      ans = false;
    }
    if (ans == false)
    {
      cout << "War" << endl;
    }
    else
    {
      cout << "No War" << endl;
    }

    return 0;
  }
