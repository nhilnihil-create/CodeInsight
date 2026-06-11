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
  int win = 0;
  for (int i=0; i<S.size(); i++) {
    if (S[i]=='o') win++;
  }
  if (win+15-S.size()>=8) cout << "YES" << endl;
  else cout << "NO" << endl;
}