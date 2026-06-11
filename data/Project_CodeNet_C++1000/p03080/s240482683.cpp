#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  string s; cin >> s;
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (s.at(i) == 'R') cnt++;
  }
  if (cnt > (N - cnt)) cout << "Yes" << endl;
  else cout << "No" << endl;
}