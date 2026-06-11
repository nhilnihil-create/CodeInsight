#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,M;
  cin >> N >> M;
  ll x[N],y[N],z[N];
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i] >> z[i];
  }
  vector<ll> S[8];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 8; j++) {
      ll res = 0;
      if ((1 << 0) & j) {
        res += x[i];
      } else {
        res -= x[i];
      }
      if ((1 << 1) & j) {
        res += y[i];
      } else {
        res -= y[i];
      }
      if ((1 << 2) & j) {
        res += z[i];
      } else {
        res -= z[i];
      }
      S[j].push_back(res);
    }
  }
  ll score[8];
  for (int i = 0; i < 8; i++) {
    sort(S[i].begin(),S[i].end());
    reverse(S[i].begin(),S[i].end());
    score[i] = 0;
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < 8; j++) {
      score[j] += S[j][i];
    }
  }

  ll ans = -9999999999999999;
  for (int i = 0; i < 8; i++) {
    ans = max(ans,score[i]);
  }
  cout << ans << endl;
  return 0;
}