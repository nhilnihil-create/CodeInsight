#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair <int, int>;
const double PI = acos(-1);
const ll MOD = 1000000007;

int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  rep(i,N){
    ll x;
    cin >> x;
    int cnt = 0;
    while(1){
      if (x % 2 == 0){
        cnt++;
        x = x / 2;
      }
      else break;
    }
    ans += cnt;
  }

  cout << ans << endl;
}
