#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<tuple<string, int, int>> data(N);
  for(int i = 0; i < N; i++) {
    string s;
    int p;
    cin >> s >> p;
    data.at(i) = make_tuple(s, 100 - p, i + 1);
  }
  sort(data.begin(), data.end());
  for(int i = 0; i < N; i++) {
    int a = get<2>(data.at(i));
    cout << a << endl;
  }
}