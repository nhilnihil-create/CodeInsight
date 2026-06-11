#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <set>
#include <math.h>
#define pai 3.14159265358979323846264338327950288;
#define keta(n) cout << fixed << setprecision((n));
using ll = long long;
int main()
{
  int n, x;
  cin >> n >> x;
  vector<int> m(n);
  int msum = 0, a = 1000;
  rep(i, n)
  {
    cin >> m[i];
    msum += m[i];
    a=min(a,m[i]);
  }
  cout << n + (x - msum) / a << endl;
}