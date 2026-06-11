#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector <pair<pair<string, int>, int>> list(N);
  string s;
  int p;
  for (int i = 0; i < N; i++) {
    cin >> s >> p;
    list.at(i) = make_pair(make_pair(s, -p), i + 1);
  }
  sort (list.begin(), list.end());
  for (int i = 0; i < N; i++) {
    cout << list.at(i).second << endl;
  }
  return 0;
}