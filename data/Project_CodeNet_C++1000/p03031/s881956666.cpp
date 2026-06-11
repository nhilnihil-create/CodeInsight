#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> D(M);
  vector<int> k(M);
  for (int i = 0; i < M; i++) {
    cin >> k.at(i);
    for (int j = 0; j < k.at(i); j++) {
      int s;
      cin >> s;
      D.at(i).push_back(s);
    }
  }
  vector<int> p(M);
  for (int i = 0; i < M; i++) {
    cin >> p.at(i);
  }
  int ans = 0;
  for (int tmp = 0; tmp < (1 << N); tmp++) {
    bitset<10> s(tmp);
    bool ok = true;
    for (int i = 0; i < M; i++) {
      int c = 0;
      for (int j = 0; j < k.at(i); j++) {
        if (s.test(D.at(i).at(j) - 1)) {
          c++;
        }
      }
      if (c % 2 != p.at(i)) {
        ok = false;
      }
    }
    if (ok) {
      ans++;
    }
  }
  cout << ans << endl;
}