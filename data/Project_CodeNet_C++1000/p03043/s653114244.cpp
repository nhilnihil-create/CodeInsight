#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
  int n,k;
  cin >> n >> k;
  double ans = 0;
  for (int i = 0; i < n; i++) {
    double cnt = 1 / (double) n;
    ll score = i+1;
    while (score < k) {
      score *= 2;
      cnt = cnt/2;      
    }
    ans += cnt;
  }
  cout << fixed << setprecision(12) << ans << endl;
  return 0;
}