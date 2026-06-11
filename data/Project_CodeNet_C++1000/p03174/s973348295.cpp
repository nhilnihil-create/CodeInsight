#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int possible[22][22];
ll Sum[1<<21];
const ll M = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin>>n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin>>possible[i][j];
    }
  }

  Sum[0] = 1;

  for (int S = 1; S < (1<<n); S++) {
    for (int i = 0; i < n; i++) {
      int w = __builtin_popcount(S);
      // w (-1) is the man being paired
      if (possible[w - 1][i]) {
        Sum[S] += Sum[S ^ (1 << i)];
        Sum[S] %= M;
      }
    }
  }

  ll res = Sum[(1<<n)-1];
  if (res < 0) res += M;
  cout<<res<<"\n";
}