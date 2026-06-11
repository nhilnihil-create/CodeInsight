#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  vector<int> N(4);
  for (int i=0; i<4; i++) cin >> N[i];
  sort(N.begin(), N.end());
  bool can = false;
  do {
    if (N[0]==1&&N[1]==9&&N[2]==7&&N[3]==4) {
      can = true;
      break;
    }
  } while (next_permutation(N.begin(), N.end()));
  if (can) cout << "YES" << endl;
  else cout << "NO" << endl;
}