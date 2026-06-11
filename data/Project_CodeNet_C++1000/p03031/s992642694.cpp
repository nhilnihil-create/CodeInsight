#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

const long long mod = 1e9+7;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M;
  cin >> N >> M;
  vector<vector<int>> s(M);
  for(int i = 0; i < M; i++) {
    int k;
    cin >> k;
    for(int j = 0; j < k; j++) {
      int S;
      cin >> S;
      s[i].push_back(S - 1);
    }
  }
  vector<int> p(M);
  for(int i = 0; i < M; i++) {
    cin >> p[i];
  }

  int ans = 0;
  for (int i = 0; i < (1 << N); ++i) {
    bool ok = true;
    for (int j = 0; j < M; ++j) {
      int c = 0;
      for (int id : s[j]) {
        // cout << id << " ";
        if ((i >> id) & 1) {
          ++c;
        }
      }
      // cout << endl;
      c %= 2;
      if (c != p[j]) {
        ok = false;
      }
    }
    if (ok) {
      ++ans;
    }
  }

  cout << ans << endl;

  return 0;
}
