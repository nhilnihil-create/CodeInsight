#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)

using namespace std;

void solve(int N, vector<int> h) {

  int ans(0);

  while (true) {
    // find the first positive in h as Left
    auto l = h.begin();
    while (*l == 0 && l != h.cend())
      ++l;
    // if no positive found, demand is satidfied
    if (l == h.cend())
      break;

    // find the first non-positive after Left in h as Right
    auto r = l;
    while (*r > 0 && r != h.cend())
      ++r;

    // reduce Left~Right in h
    for (auto i = l; i != r; ++i)
      (*i)--;

    ans++;
  }
  cout << ans << endl;
    
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> h(N);
  REP(i, N)
    cin >> h[i];

  solve(N, move(h));
  return 0;
}
