#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  vector<vector<char>> c(3, vector<char>(3));
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) cin >> c[i][j];
  }
  cout << c[0][0] << c[1][1] << c[2][2] << endl;
}