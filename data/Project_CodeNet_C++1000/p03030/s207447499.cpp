#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  using pp = pair<pair<string, int>, int>;
  vector<pp> data(N);
  for(int i = 0; i < N; i++) {
    string s;
    int p;
    int sec = i + 1;
    cin >> s >> p;
    data.at(i) = make_pair(make_pair(s, -p), sec);
  }
  sort(data.begin(), data.end());
  for(int i = 0; i < N; i++) {
    cout << data.at(i).second << endl;
  }
}