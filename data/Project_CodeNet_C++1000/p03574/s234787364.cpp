#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

int main() {
  
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  rep(i,H) cin >> S[i];
  
  rep(i,H) {
    rep(j,W) {
      if (S[i][j] == '#') {
        cout << '#';
        continue;
      }
      int count = 0;
      for (int y = -1; y <= 1; y++) for (int x = -1; x <= 1; x++) {
        if (i + y < 0 || i + y >= H || j + x < 0 || j + x >= W) continue;
        if (S[i + y][j + x] == '#') count++;
      }
      cout << count;
    }
    cout << endl;
  }

  return 0;
}