#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
int main()
{
    int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
 
  vector<P> ps(n);
  rep(i, n) ps[i] = make_pair(a[i], b[i]);
  sort(ps.begin(), ps.end());
  ll ans = 0;
  rep(i, n) {
    if (m == 0) break;
    ans += (ll)ps[i].first * min(m, ps[i].second);
    m -= min(m, ps[i].second);
  }
  cout << ans << endl;
    return 0;
}