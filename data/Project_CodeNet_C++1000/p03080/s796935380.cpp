#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N, red = 0;
  string s;
  cin >> N >> s;
  for (int i=0; i<N; i++) {
    if (s[i]=='R') red++;
  }
  if (2*red>N) cout << "Yes" << endl;
  else cout << "No" << endl;
}