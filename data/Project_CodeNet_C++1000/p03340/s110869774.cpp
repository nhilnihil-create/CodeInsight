#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> acc(n + 1, vector<int>(20));
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    for(int j = 0; j < 20; j++) {
      acc[i + 1][j] = acc[i][j] + (a & 1);
      a >>= 1;
    }
  }
  int e = 1;
  ll o = 0;
  for(int b = 0; b < n; b++) {
    int d[20], m;
    for(; e < n + 1; e++) {
      m = 0;
      for(int i = 0; i < 20; i++) {
        d[i] = acc[e][i] - acc[b][i];
        m = max(m, d[i]);
      }
      if(m > 1) break;
    }
    o += e - b - 1;
  }
  cout << o << '\n';
}