#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll N;
  cin >> N;
  vector<ll> v(N);
  vector<pair<ll, ll>> m_o(100001, {0, 0}), m_e(100001, {0, 0});
  for (int i = 0; i < N; i++) {
    cin >> v[i];
    if (i % 2 == 0) {
      m_o[v[i]].first++;
      m_o[v[i]].second = v[i];
    } else {
      m_e[v[i]].first++;
      m_e[v[i]].second = v[i];
    }
  }
  sort(m_o.rbegin(), m_o.rend());
  sort(m_e.rbegin(), m_e.rend());
  ll ans = 0;
  ll o_first = m_o[0].second;
  ll e_first = m_e[0].second;
  ll o_second = (m_o[1].first != 0) ? m_o[1].second : o_first;
  ll e_second = (m_e[1].first != 0) ? m_e[1].second : e_first;
  if (o_first == o_second && o_first == e_first && e_first == e_second) {
    ans = N / 2;
  } else if (o_first != e_first) {
    for (int i = 0; i < N; i++) {
      if (i % 2 == 0 && v[i] != o_first) {
        ans++;
      }
      if (i % 2 == 1 && v[i] != e_first) {
        ans++;
      }
    }
  } else {
    ll cand1 = 0, cand2 = 0;
    for (int i = 0; i < N; i++) {
      if (i % 2 == 0 && v[i] != o_first) {
        cand1++;
      }
      if (i % 2 == 1 && v[i] != e_second) {
        cand1++;
      }
    }
    for (int i = 0; i < N; i++) {
      if (i % 2 == 0 && v[i] != o_second) {
        cand2++;
      }
      if (i % 2 == 1 && v[i] != e_first) {
        cand2++;
      }
    }
    ans = min(cand1, cand2);
  }
  cout << ans << endl;
  return 0;
}