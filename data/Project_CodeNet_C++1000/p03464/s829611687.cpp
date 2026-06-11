#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int k;
  cin >> k;
  vector<ll> a(k);

  rep(i,k) cin >> a[i];

  ll l = 2, r = 2;

  for (int i = k-1; i >= 0; i--) {
    l = (l + a[i] - 1) / a[i] * a[i];
    if (r < l) {
      puts("-1");
      return 0;
    }
    r = (r / a[i] + 1) * a[i] - 1;
  }
  cout << l << " " << r << endl;
  return 0;
}