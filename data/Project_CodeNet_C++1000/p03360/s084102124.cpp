#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  int maxnumber = max(a, max(b, c));
  int sum = a+b+c;
  int md = sum - maxnumber;
  rep(i, k) {
    maxnumber *= 2;
  }
  int ans = md + maxnumber;
  cout << ans << endl;
  return 0;
}