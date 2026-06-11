#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int ans = 0;
  for (int i = 1; i < N; i++) {
    string x = S.substr(0, i);
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    string y = S.substr(i);
    int cnt = 0;
    for (int j = 0; j < x.size(); j++) {
      if (count(y.begin(), y.end(), x.at(j))) cnt++;
    }
    ans = max(ans, cnt);
  }
  cout << ans << "\n";
}