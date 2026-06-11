#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i <= (n); ++i)

using namespace std;

void solve(int R, int G, int B, int N) {
  int ans = 0;
  rep(r, floor(N / R))
    rep(g, floor((N - r * R) / G))
    if ((N - r * R - g * G) % B == 0)
      ans++;
  cout << ans <<endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int R, G, B, N;
  cin >> R >> G >> B >> N;
  solve(R, G, B, N);
  return 0;
}
