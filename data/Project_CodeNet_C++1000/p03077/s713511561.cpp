#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
typedef long long ll;

int main() {
  ll N;
  cin >> N;
  vector<ll> v(5);
  rep(i,0,4) cin >> v[i];

  ll min = *min_element(v.begin(), v.end());
  if (N <= min) {
    cout << 5 << endl;
    return 0;
  }

  ll t = (N + min - 1) / min;
  cout << t + 4 << endl;
  return 0;
}
