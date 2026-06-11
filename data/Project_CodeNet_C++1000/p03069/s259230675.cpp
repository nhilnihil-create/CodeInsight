#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<pair<int, int>> WB(N); // S_iまでにある白と黒のマスの個数
  if (S[0]=='.') {
    WB[0].first = 1;
    WB[0].second = 0;
  }
  else {
    WB[0].first = 0;
    WB[0].second = 1;
  }
  for (int i=1; i<N; i++) {
    if (S[i]=='.') {
      WB[i].first = WB[i-1].first+1;
      WB[i].second = i+1-WB[i].first;
    }
    else {
      WB[i].second = WB[i-1].second+1;
      WB[i].first = i+1-WB[i].second;
    }
  }
  int ans = min(N-WB[N-1].first, N-WB[N-1].second);
  // S_iより左は.，S_iより右は#
  for (int i=0; i<N-1; i++) ans = min(ans, WB[i].second+WB[N-1].first-WB[i].first);
  cout << ans << endl;
}