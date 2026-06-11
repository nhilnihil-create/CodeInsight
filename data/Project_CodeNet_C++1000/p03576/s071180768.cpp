#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,K;
  cin >> N >> K;
  ll x[N],y[N];
  vector<ll> xlis;
  vector<ll> ylis;
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
    xlis.push_back(x[i]);
    ylis.push_back(y[i]);
  }
  sort(xlis.begin(),xlis.end());
  sort(ylis.begin(),ylis.end());
  ll ans = Mod * Mod * 4;
  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      for (int k = 0; k < N; k++) {
        for (int l = k+1; l < N; l++) {
          int cnt = 0;
          for (int m = 0; m < N; m++) {
            if (xlis[i] <= x[m] && x[m] <= xlis[j] && ylis[k] <= y[m] && y[m] <= ylis[l]) {
              cnt++;
            }
          }
          if (cnt >= K) {
            ans = min(ans,(xlis[j] - xlis[i]) * (ylis[l] - ylis[k]));  
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}