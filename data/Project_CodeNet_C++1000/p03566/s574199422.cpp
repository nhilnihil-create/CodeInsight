#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
const ll INF = 1LL<<60;

int main()
{
  int n; cin >> n;
  vector<int> t(n);
  int sum = 0;
  rep(i, n) {
    cin >> t[i];
    t[i] *= 2;
    sum += t[i];
  }
  vector<double> v(n);
  rep(i, n) cin >> v[i];
  vector<double> maxv(sum+1, 1001001001.0);
  maxv[0] = 0;
  maxv[sum] = 0;
  int ti = 1;
  rep(i, n) {
    ti--;
    rep(j, t[i]+1) {
      maxv[ti] = min(maxv[ti], v[i]);
      ti++;
    }
  }

  for (int i=1; i<sum; i++) {
    maxv[i] = min(maxv[i], maxv[i-1]+0.5);
  }
  for (int i=sum-1; i>=0; i--) {
    maxv[i] = min(maxv[i], maxv[i+1]+0.5);
  }
  double ans = 0;
  for (int i=1; i<=sum; i++) {
    ans += (maxv[i-1]+maxv[i])/4;
  }
  printf("%.10lf\n", ans);

  return 0;
}
