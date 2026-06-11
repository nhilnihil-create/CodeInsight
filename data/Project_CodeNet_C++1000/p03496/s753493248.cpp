#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll, ll> > vec;

int main() {
  ll N;
  vector<ll> a;
  ll max_abs = -1, idx;

  cin >> N;
  for (ll i = 0; i < N; i++) {
    ll t;
    cin >> t;
    a.push_back(t);
    if(abs(t) > max_abs) {
      max_abs = abs(t);
      idx = i;
    }
  }

  bool plus = (a[idx] >= 0 ? true : false);

  for (ll i = 0; i < N; i++) {
    a[i] += a[idx];
    vec.push_back({idx + 1, i + 1});
  }

  if (plus) {
    for (ll i = 0; i < N - 1; i++) {
      a[i + 1] += a[i];
      vec.push_back({i + 1, i + 2});
    }
  } else {
    for (ll i = N -1;  i >= 1; i--) {
      a[i - 1] += a[i];
      vec.push_back({i + 1, i});
    }
  }

  cout << vec.size() << endl;
  for (auto itr = vec.begin(); itr != vec.end(); itr++) {
    cout << itr->first << " " << itr->second << endl;
  }
  return 0;
}