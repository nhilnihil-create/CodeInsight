#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  ll N;
  cin >> N;
  ll ans = 1e8;
  vector<ll> six(0), nine(0);
  int tmp = 1;
  while (true) {
    six.push_back(tmp);
    tmp *= 6;
    if (N < tmp) break;
  }
  tmp = 1;
  while (true) {
    nine.push_back(tmp);
    tmp *= 9;
    if (N < tmp) break;
  }
  reverse(six.begin(), six.end());
  reverse(nine.begin(), nine.end());
  for (int i = 0; i <= N; i++) {
    // i==6^nで支払う金額
    ll cnt = 0;
    ll a = i, b = N - i;
    int j = 0;
    while (a > 0) {
      while (six[j] <= a) {
        cnt++;
        a -= six[j];
      }
      j++;
    }
    j = 0;
    while (b > 0) {
      while (nine[j] <= b) {
        cnt++;
        b -= nine[j];
      }
      j++;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
}