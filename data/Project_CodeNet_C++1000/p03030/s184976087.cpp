#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<tuple<string, int, int>> A;
  for (int i = 1; i <= N; i++) {
    string S;
    int P;
    cin >> S >> P;
    A.emplace_back(S, -P, i);
  }
  sort(A.begin(), A.end());
  rep(i, N) {
    cout << get<2>(A[i]) << '\n';
  }
  return 0;
}