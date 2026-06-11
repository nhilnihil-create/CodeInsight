#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main() {
  int N;
  cin >> N;
  vector<tuple<string, int, int>> Sp(N);
  rep(i, N) {
    string S;
    int p;
    cin >> S >> p;
    get<0>(Sp.at(i)) = S;
    get<1>(Sp.at(i)) = - p;
    get<2>(Sp.at(i)) = i + 1;
  }
  sort(Sp.begin(), Sp.end());
  rep(i, N) cout << get<2>(Sp.at(i)) << endl;
}
