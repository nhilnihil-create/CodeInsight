#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  int MIN = 1e9;
  int ans = MIN;
  rep(i, n) {
    int a;
    cin >> a;
    int cnt = 0;
    while(a % 2 == 0) {
      a /= 2;
      cnt++;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}