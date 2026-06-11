#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  string S;
  cin >> S;
  bool keyence = false;
  for (int i=0; i<S.size(); i++) {
    for (int j=0; j<=S.size()-i; j++) {
      string S_copy = S;
      S_copy.erase(i, j);
      if (S_copy=="keyence") {
        keyence = true;
        break;
      }
    }
    if (keyence) break;
  }
  if (keyence) cout << "YES" << endl;
  else cout << "NO" << endl;
}