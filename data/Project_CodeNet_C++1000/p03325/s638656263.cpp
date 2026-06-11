#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int a[100010]; 
int main() {
  int n;
  cin >> n;
  rep(i,n) cin >> a[i];
  int ans = 0;
  rep(i,n) {
    int cnt = 0;
    while (a[i] % 2 == 0)
    {
      a[i] /= 2;
      cnt++;
    }
    ans += cnt;
  }
  cout << ans << endl;
  return 0;
}