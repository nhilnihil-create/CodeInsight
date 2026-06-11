#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main() {
  string str; cin >> str;
  ll N = str.size();
  ll s[N+1];
  s[0] = 1;
  for (ll i = 0; i < N; i++) {
    s[i+1] = str[i] - '0';
  }
  if (s[1] == 0) {cout << -1 << endl; return 0;}
  if (s[N] == 1) {cout << -1 << endl; return 0;}
  for (ll i = 1; i <= N-1; i++) {
    if (s[i] != s[N-i]) {cout << -1 << endl; return 0;}
  }
  ll from = 0;
  vector<P> es;
  for (ll i = 1; i <= N-1; i++) {
    if (s[i-1] == 1 && from == i-1) {
      from++;
      es.push_back(P(from, i+1));
    }
    if (s[i-1] == 1 && from < i-1) {
      from = i;
      es.push_back(P(from, i+1));
    }
    if (s[i-1] == 0) {
      es.push_back(P(from, i+1));
    }
  }
  for (ll i = 0; i < es.size(); i++) {
    cout << es[i].first << " " << es[i].second << endl;
  }
}