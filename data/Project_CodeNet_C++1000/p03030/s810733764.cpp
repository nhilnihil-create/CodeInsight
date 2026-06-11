#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<tuple<string, int, int>> vec(N);
  for (int i=0; i<N; i++) {
    string s;
    int p;
    cin >> s >> p;
    vec.at(i) = make_tuple(s, -p, i+1);
  }

  sort(vec.begin(), vec.end());

  int ind;
  for (int i = 0; i < N; i++) {
    tie(ignore, ignore, ind) = vec.at(i);
    cout << ind << endl;
  }
}
