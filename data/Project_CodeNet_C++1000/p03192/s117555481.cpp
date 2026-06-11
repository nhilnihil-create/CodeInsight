#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  string N;
  cin >> N;
  int ans = 0;
  for (int i=0; i<N.size(); i++) {
    if (N[i]=='2') ans++;
  }
  cout << ans << endl;
}