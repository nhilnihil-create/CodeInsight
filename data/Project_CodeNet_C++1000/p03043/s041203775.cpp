#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  double n,k; cin >> n >> k;
  double ans = 0;
  for (ll i = 1; i <= n; i++) {
    double c = max(ceil(log2(k/i)), (double)0);
    ans += (1 / n) * pow(0.5,c);
  }
  printf("%.12f\n",ans);
}