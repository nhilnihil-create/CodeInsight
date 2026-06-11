#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s(ll n) {
  ll res = 0;
  while (n) {
    res += n % 10;
    n /= 10;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  ll base = 0;
  ll cnt = 0;
  vector<pair<ll,double>> ans;
  for (ll base = 0; base <= 1e16-1; base = base * 10 + 9) {
    ll mul = 1LL;
    for (int i = 0; i < cnt; i++) {
      mul *= 10;
    }
    for (ll p = 1; p < 150; p++) {
      ll tmp = p * mul + base;
      ans.push_back(make_pair(tmp, (double)tmp / (double)s(tmp)));
    }
    cnt++;
  }
  sort(ans.begin(),ans.end());
  vector<ll> out;
  double mi = ans.back().second;
  ll before = -1;
  for (int i = ans.size() - 1; i >= 0; i--) {
    if (ans[i].second <= mi && ans[i].first != before) {
      mi = ans[i].second;
      before = ans[i].first;
      out.push_back(before);
    }
  }
  sort(out.begin(), out.end());
  for (int i = 0; i < k; i++) {
    cout << out[i] << endl;
  }
  return 0;
}
