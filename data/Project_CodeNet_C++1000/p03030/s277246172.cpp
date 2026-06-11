#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, p;
  string s;
  cin >> N;
  vector<pair<pair<string, int>, int>> rest(N);
  for(auto i = 0; i < N; i++) {
    cin >> s >> p;
    rest.at(i).first.first = s;
    rest.at(i).first.second = -p;
    rest.at(i).second = i + 1;
  }
  sort(rest.begin(), rest.end());
  for(auto i : rest) {
    cout << i.second << endl;
  }
}