#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  vector<vector<int>> cs(26), ct(26);
  for (int i = 0, n = S.size(); i != n; ++i) {
    cs[S[i] - 'a'].push_back(i);
    ct[T[i] - 'a'].push_back(i);
  }

  sort(begin(cs), end(cs));
  sort(begin(ct), end(ct));

  cout << (cs == ct ? "Yes" : "No") << endl;
}
