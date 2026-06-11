#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using vi  = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<tuple<string, int, int>> sp;
  rep(i, N) {
    string s;
    int p;
    cin >> s >> p;
    sp.push_back(make_tuple(s, p*-1, i+1));
  }
  sort(sp.begin(), sp.end());
  for (auto x : sp) {
    cout << get<2>(x) << endl;
  }
}
