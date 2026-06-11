#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;
  int q_count;
  cin >> q_count;
  for (int q = 0; q < q_count; q++) {
    int k;
    cin >> k;

    int64 ans = 0;
    int64 m_count = 0;
    int64 c_count = 0;
    int64 delta = 0;
    for (int i = 0; i < k; i++) {
      if (s[i] == 'M') m_count++;
      if (s[i] == 'C') {
        delta += m_count;
        c_count++;
      }
    }
    if (s[0] == 'D') {
      if (DEBUG) cout << "@0 " << delta << endl;
      ans += delta;
    }

    for (int i = k; i < n; i++) {
      if (s[i] == 'M') m_count++;
      if (s[i] == 'C') {
        delta += m_count;
        c_count++;
      }
      if (s[i - k] == 'M') {
        m_count--;
        delta -= c_count;
      }
      if (s[i - k] == 'C') {
        c_count--;
      }

      if (DEBUG) cout << "@" << i - k + 1 << " "  << m_count << " " << c_count << " " << delta << endl;
      if (s[i - k + 1] == 'D') {
        if (DEBUG) cout << "@" << i - k + 1 << " "  << delta << endl;
        ans += delta;
      }
    }

    for (int i = n - k; i < n; i++) {
      if (DEBUG) cout << "@" << i << " "  << m_count << " " << c_count << " " << delta << endl;
      if (i > n - k && s[i] == 'D') {
        if (DEBUG) cout << "@" << i << " "  << delta << endl;
        ans += delta;
      }
      if (s[i] == 'M') {
        m_count--;
        delta -= c_count;
      }
      if (s[i] == 'C') {
        c_count--;
      }
    }
    cout << ans << endl;
  }
}