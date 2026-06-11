#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int main(){
  ll N, M;
  cin >> N >> M;

  vector<pair<ll, ll>> X(N);

  rep(i, N){
    cin >> X[i].first >> X[i].second;
  }

  sort(X.begin(), X.end());

  ll cnt = 0;
  ll ans = 0;
  ll res = M;
  while (res > 0){
    ans += X[cnt].first * min(res, X[cnt].second);
    res -= X[cnt].second;
    cnt ++;
  }
  cout << ans << endl;
}