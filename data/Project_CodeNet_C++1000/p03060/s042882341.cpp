#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;
#define ALL(x) x.begin(),x.end()
#define P pair<int,int>
#define MOD 1000000007

int main()
{
  int n, c;
  int ans = 0;
  cin >> n;
  vector<int> v(n);
  rep(i, n) {
    cin >> v[i];
  }
  rep(i, n) {
    cin >> c;
    if (v[i] > c) ans += v[i] - c;
  }
  cout << ans << endl;

  return 0;
}
