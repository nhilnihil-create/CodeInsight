#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <map>
#include <random>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
#define rep(i,a,b) for(int i=a;i<(b);++i)
constexpr long INF = 1L << 60;
constexpr int MOD = 1e9 + 7;

int n;
string a,b,c;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);

  cin >> n >> a >> b >> c;
  int ans = 0;
  for(int i = 0;i < n; ++i) {
    if(a[i]==b[i]&&b[i]==c[i]) continue;
    if(a[i]==b[i]||b[i]==c[i]||c[i]==a[i]) ++ans;
    else ans += 2;
  }
  cout << ans;
  return 0;
}