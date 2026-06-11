#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> vec(m);
  rep(i, m) cin >> vec[i];
  sort(vec.begin(), vec.end());
  vector<int> d;
  rep(i, m-1) d.push_back(abs(vec[i+1] - vec[i]));
  sort(d.begin(), d.end());
  ll ans = 0;
  int s = d.size() - (n-1);
  rep(i, s) {
    ans += d[i];
  }
  
  cout << ans << endl;
  return 0;
}