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
  int n, t, a;
  cin >> n >> t >> a;
  double k, mn = 1e9;
  vector<int> h(n);
  rep(i, n)
  {
    cin >> h[i];
  }
  int ans;
  rep(i, n)
  {
    k = t - h[i] * 0.006;
    mn = min(mn, abs(k - a));
    if (mn == abs(k - a))
      ans = i;
  }
  cout<< ans + 1 << endl;
}