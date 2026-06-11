#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  string s;
  int K;
  cin >> s;
  cin >> K;

  set<string> candidate;
  for (int i = 'a'; i <= 'z'; i++) {
    if (candidate.size() >= K) break;
    for (int j = 0, N = s.size(); j < N; j++) {
      if (s[j] == i) {
        for (int i = 1; i <= 5; i++) {
          if (j + i <= N) candidate.insert(s.substr(j, i));
        }
      }
    }
  }

  vector<string> v(candidate.size());
  copy(candidate.begin(), candidate.end(), v.begin());
  sort(v.begin(), v.end());
  cout << v[K - 1] << endl;
}
