#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string s;
  int p;
  vector<tuple<string, int, int>> guide(N);
  for (int i = 0; i < N; i++) {
    cin >> s >> p;
    guide.at(i) = make_tuple(s, -p, i + 1);
  }
  
  int ans;
  sort(guide.begin(), guide.end());
  for (auto e : guide) {
    tie(ignore, ignore, ans) = e;
    cout << ans << endl;
  }
}
