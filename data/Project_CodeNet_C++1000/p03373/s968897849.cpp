#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define drep(i,n) for (int i = n; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define RALL(a) (a).rbegin(), (a).rend()
using namespace std;
typedef long long ll;

int gcd(int a, int b)
{
   if (a%b == 0) return(b);
   else          return(gcd(b, a%b));
}
int lcm(int a, int b)
{
   return a * b / gcd(a, b);
}
void printvv(vector<vector<auto>> vv, int n)
{
  cout << '[' << endl;
  rep(q, n)
  {
    cout << '[';
    rep(p, n)
    {
      cout << vv.at(q).at(p) << ',';
    }
    cout << ']' << endl;
  }
  cout << ']' << endl;
}


//------------------------------------------------------------
int main() {
  int a, b, c, x, y, sum=0, common;
  cin >> a >> b >> c >> x >> y;

  common = min(x, y);

  if (a+b > 2*c)
  {
    sum += common * 2*c;
  }
  else
  {
    sum += common * (a+b);
  }

  x -= common; y -= common;

  if (x == 0)
  {
    sum += b > 2*c ? y*2*c : y*b;
  }
  else
  {
    sum += a > 2*c ? x*2*c : x*a;
  }

  cout << sum << endl;

  return 0;
}
