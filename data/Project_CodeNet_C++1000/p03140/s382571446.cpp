#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  string A, B, C; cin >> A >> B >> C;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    set<char> s;
    s.insert(A.at(i));
    s.insert(B.at(i));
    s.insert(C.at(i));
    if (s.size() == 1) continue;
    else if (s.size() == 2) ans++;
    else ans += 2;
  }
  cout << ans << endl;
}