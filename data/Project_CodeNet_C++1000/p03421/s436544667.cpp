#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

void compress(vector<ll> &x) {
  vector<ll> v(x.size());
  REP(i, 0, x.size()) v[i] = x[i];
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  REP(i, 0, x.size()) x[i] = lower_bound(v.begin(), v.end(), x[i]) - v.begin();
}

int main(void) {
  ll N, A, B;
  cin >> N >> A >> B;

  if(A + B - 1 <= N && N <= A * B) {
    vector<ll> ans;
    ll cnt = 0, limit = N - B;
    REP(i, 0, B) {
      ans.push_back(B - i);
      REP(j, 1, A) {
        if(cnt >= limit) break;
        ans.push_back((B - i) + B * j);
        cnt++;
      }
    }

    compress(ans);

    REP(i, 0, ans.size()) cout << ans[i] + 1 << (i + 1 != ans.size() ? " " : "\n");
  } else {
    cout << -1 << endl;
  }
}
