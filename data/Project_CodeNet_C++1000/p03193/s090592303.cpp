#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  ll N, H, W;
  cin >> N >> H >> W;
  ll X, Y;
  ll co = 0;
  rep(i, N) {
    cin >> X >> Y;
    if(X >= H && Y >= W) {
      co++;
    }
  }
  cout << co << endl;
}