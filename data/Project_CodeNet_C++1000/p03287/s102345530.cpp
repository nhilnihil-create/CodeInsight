#include <iostream>
#include <unordered_map>
typedef long long ll;
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main() {
  int n, m;
  cin >> n >> m;

  int s = 0;
  unordered_map<int, int> mp;
  rep(i, n) {
    int a;
    cin >> a;
    s += a;
    s %= m;
    mp[s]++;
  }

  ll ans = 0;
  for(auto x : mp) {
    int cnt = x.second;
    ans += (ll)cnt * (cnt - 1) / 2;
    if(x.first == 0) ans += (ll)cnt;
  }
  cout << ans << endl;
  return 0;
}