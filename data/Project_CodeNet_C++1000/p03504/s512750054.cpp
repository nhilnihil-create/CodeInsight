#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;
  int C; cin >> C;
  vector<pair<pair<int, int>, int>> A(N);
  for (int i = 0; i < N; i++) {
    int s; cin >> s;
    int t; cin >> t;
    int c; cin >> c;
    A[i] = make_pair(make_pair(s, t), c);
  }

  sort(A.begin(), A.end());
  set<pair<pair<int, int>, int>> st;

  for (int i = 0; i < N; i++) {
    pair<pair<int, int>, int> a = A[i];
    bool ok = false;
    for (auto p: st) {
      if (a.first.first > p.first.second) ok = true;
      if (a.first.first == p.first.second && a.second == p.second) ok = true;
      if (ok) {
        st.erase(p);
        st.insert(a);
        break;
      }
    }
    if (!ok) {
      st.insert(a);
    }
  }
  cout << st.size() << '\n';
  return 0;
}