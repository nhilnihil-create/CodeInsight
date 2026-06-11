#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  using tsii = tuple<string, int, int>;
  using v = vector<tsii>;
  
  v p(N);
  for (int i = 0; i < N; i++) {
    string s;
    int score;
    cin >> s >> score;
    p.at(i) = make_tuple(s, -score, i + 1); // HINT 問題のソート順を考えるとスコアは逆転すると簡単
  }
  
  sort(p.begin(), p.end());
  
  for (auto e : p) {
    cout << get<2>(e) << endl;
  }
}
